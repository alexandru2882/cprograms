/*
Nume: Alexandru Popovici
An: AN1 ID, Semestrul 1, Grupa 108

Denumire program: Ghiceste cuvantul secret

Descriere program:
Utilizatorul incearca sa ghiceasca un cuvant secret format din 4 litere 
si are la dispozitie 10 incercari. Dupa ce a introdus un cuvant de 4 litere,
toate diferite, programul va afisa daca una sau mai multe litere se regasesc
in cuvantul secret si daca ele se alfa in pozitia corecta in cuvantul secret. 
La sfarsitul jocului utilizatorul poate reincerca cu un cuvant nou ales aleatoriu. 

Continut program :
-la fiecare joc nou, un cuvant va fi ales aleatoriu dintr-un array
-cuvantul introdus de catre utilizator este verificat si trebuie sa aiba:
	-numarul corect de litere
	-litere unice
	-doar litere mici
	-nicio cifra
-compararea cuvantului secret cu cel introdus de catre utilizator:
	-daca cuvantul a fost ghicit, in caz contrar:
	-afisarea literelor care sunt la pozitia corecta
	-afisarea literelor ce sunt in cuvant dar nu se afla la pozitia corecta
-numar finit de incercari
-posibilitatea de a reincepere un joc nou
*/



// declarare functii
int regulile(void);
char *cuvantul(void);
int vf_nr_incercare(char *cuvantul_secret);
int reincearca(void);
int comparare_cuvinte(char *cuvantul_secret, char *cuvant, int lungime_cs, int dim);
int jocul_ghiceste();
void clrscreen();

// variabile globale
int i, j, n;
// cuvantul ce trebuie ghicit
char *cuvantul_secret;
// lungimea cuvantului secret
int lungime_cs;
// cuvantul introdus de catre utilizator pt a fi ghicit: trebuie sa fie de 4 litere (plus caracterul de final)
/* are 10 biti: permite introducerea de la tastatura de cuvinte mai lungi de 4 caractere
pentru a permite verificarea dimensiunii cuvantului introdus */
char cuvant[10];
// pt a verifica lungimea cuvantului
int dim;

//aici incepe sa ruleze programul
//int main()
//{	
//	jocul_ghiceste();
//	return 0;
//}// end MAIN

// la inceputul jocului afiseaza regulile
int regulile(void){
	printf("Ghiceste cuvantul secret! \n\n");
    printf("Jocul este simplu: exista un cuvant secret, format din 4 litere unice, \n");
    printf("pe care tu va trebui sa-l descoperi. Dupa ce vei introduce un cuvant,  \n");
    printf("vei fi anuntat daca literele din cuvantul introdus de tine se \n");
    printf("regasesc in cuvantul secret sau nu, si daca sunt la pozitia corecta.\n");
    printf("Ai doar 10 incercari. Succes!\n");
    printf("Pentru a iesi, apasa CTRL + C.\n\n");
}

// functie ce returneaza cuvantul secret
char * cuvantul(void) {
	// lista de cuvinte
	char *cuvinte_de_4_litere[] = { "ceva", "ikea", "salt", "sare", "bine", "dans", "lume", "sora", "sine", "oaie", "ager", "acum", "arde", "parc", "crin", "ecou" };
	
	// numarul de cuvinte din array
	int dimensiune_array = sizeof(cuvinte_de_4_litere) / sizeof(cuvinte_de_4_litere[0]);
	
	// creez un numar random
	srand(time(NULL));
	int nr_random = rand() % dimensiune_array;
	
	// cuvantul secret care va trebui ghicit de catre utilizator
	char *cuvantul_secret = cuvinte_de_4_litere[nr_random];
	
	return cuvantul_secret;
}

// verific si afisez numarul incercarii curente
int vf_nr_incercare(char *cuvantul_secret){
	if (n < 9){
		// 'n' e initializat la 0, deci prima incercare va avea valoarea n+1
		printf("\nIncercarea nr. %i\n", n+1);
	} else if (n < 10){
		printf("\nIncercarea nr. %i. Ultima incercare.\n", n+1);
	} else {
		printf("\nAI PIERDUT\n\n");
		//afisez cuvantul care nu a putut fi ghicit
		printf("Cunvantul era: '%s'\n", cuvantul_secret);
		//intreb utilizatorul daca vrea sa mai incerce o data
		reincearca();
	}
}

// permite reinceperea jocului daca au fost consumate toate incercarile sau daca cuvantul a fost gasit
int reincearca(void){
	char replay[] = "Da";
	printf("\nVrei sa mai joci o data? Da\\Nu\n");
	scanf("%s", replay);
	
	//se poate raspunde cu 'Da' sau 'da'
	if (strcasecmp (replay, "da") == 0){
		printf("\n");
		printf("\n");
		jocul_ghiceste();
		
	// orice alt raspuns va avea ca rezultat oprirea programului
	} else {
		printf("\nImi pare rau, ne vedem data viitoare!\n");
		clrscreen();
		main();
		//exit(0);
	}
}

// compar litere introduse de la tastatura cu cu literele din cuvantul secret
int comparare_cuvinte(char *cuvantul_secret, char *cuvant, int lungime_cs, int dim) {
	// compar litere introduse de la tastatura cu cu literele din cuvantul secret
	if (strcasecmp(cuvantul_secret, cuvant) == 0) {	
		// verific cazul in care cuvantul e ghicit din prima incercare
		if (n == 0){
			printf("\nFELICITARI! Ai gasit cuvantul din prima incercare!\n\n");
			// ofer posibilitatea reinceperii unui nou joc
			reincearca();
		} else {
			printf("\nFELICITARI! Ai gasit cuvantul din %i incercari!\n\n", n+1);
			reincearca();
		}
	} else {
		// daca cuvantul nu a fost ghicit
	    for (i = 0; i < lungime_cs; i++) {
	    	for (j = 0; j < dim; j++ ){
	    		// verific in cuvantul secret fiecare litera din cuvantul introdus de catre utilizator		    			    		
	    		if(cuvantul_secret[i] == cuvant[j]){
	    			//verific daca litera introdusa se regaseste pe pozitia unei litere din cuvantul secret
	    			if (i == j) {
	    				printf("Litera '%c' se afla la pozitia corecta.\n", cuvant[j]);
	    			//verific daca litera introdusa se afla in alta pozitie in cuvantul secret
					} else {
						printf("Litera '%c' se afla in cuvant dar nu este la pozitia corecta.\n", cuvant[j]);
					}
				} 	
			}//end for 2 verificare
		}//end for 1 verificare		
	} // end if else comparatie
}

int jocul_ghiceste(){
	
    // incarc regulile jocului, ce vor fi afisate la inceputul fiecarui joc
	regulile();
	
	// cuvantul secret, ce trebuie ghicit
	cuvantul_secret = cuvantul();
	
	// lungimea cuvantului secret
	lungime_cs = strlen(cuvantul_secret);
	
	// utilizatorul va avea 10 incercari pentru a ghici numarul
	// n = 11 pentru a putea rula ulimul else (in cazul in care a pierdut jocul)
	for (n = 0; n < 11; n++){
		
		// verific si afisez numarul incercarii curente
		vf_nr_incercare(cuvantul_secret);

		// utilizatorul introduce de la tastatura un cuvant
		label: printf("\nIntrodu cuvantul:  ");
		/*folosesc label pentru a-i permite utilizatorului
		sa reintroduca un cuvant daca a facut o greseala*/
		
		//permit introducerea unui cuvant de maxim 9 caractere
		scanf("%9s", &cuvant);
		//in viitor e posibil sa implementez ghicirea unui cuvant mai lung de 4 caractere
		
		printf("\n");
		
		// verific lungimea cuvantului > trebuie sa fie de exact 4 cartactere
		dim = strlen(cuvant);
		
		// cuvantul are mai mult de 4 caractere
    	if (dim > lungime_cs) {
    		printf("Cuvantul este mai mare de %i litere.\n", lungime_cs);
			printf("Scrie te rog un alt cuvant care sa aiba doar %i caractere.\n", lungime_cs);
			goto label;
		// cuvantul are mai putin de 4 caractere
		} else if (dim < lungime_cs){
			printf("Cuvantul are mai putin de %i litere.\n", lungime_cs);
			printf("Scrie te rog un alt cuvant care sa aiba %i caractere.\n", lungime_cs);
			goto label;
		}
    	
    	//verific daca au fost introduse cifre
		for (i = 0; i < dim; i++) {
			for (j = 0; j < dim; j++ ){
				// verific daca sunt litere mici
				if (cuvant[j] >= 'a' && cuvant[j] <= 'z'){ 
					continue;
				// verfic daca sunt litere mari si afisez o eroare
				} else if(cuvant[j] >= 'A' && cuvant[j] <= 'Z'){ 
					printf("Ai introdus in cuvant litere mari.\n");
					printf("Scrie te rog un alt cuvant, format doar din litere mici.\n");
					//ii permit utilizatorului sa reintroduca cuvantul fara piarda o incercare
					goto label;	
				//verfic daca sunt cifre si afisez o eroare
				} else { 
					printf("Ai introdus din greseala numarul %c.\n", cuvant[j]);
					printf("Scrie te rog un alt cuvant, si ai grija ca sa fie format numai din litere.\n");
					goto label;	
				}
			}
    	}//end for verificare cifre
    	
		//verific daca se repeta litere in cuvantul introdus de catre utilizator
		for (i = 0; i < dim; i++) {
			for (j = 0; j < dim; j++ ){
			 	//verific fiecare litera
				if(cuvant[i] == cuvant[j]) {
					// tebuie sa exclud literele care se afla pe aceeasi pozitie
				 	if (i==j){
						continue;
					// verific daca doua litere care se afla pe pozitii diferite coincid
					} else { 
						printf("Litera '%c' se repeta.\n", cuvant[j]);
						printf("Scrie te rog un alt cuvant, si ai grija ca fiecare litera sa fie unica.\n");
						//ii dau posibilitatea sa reintroduca cuvantul fara sa-l penalizez
						goto label;
					}
				} //end_if
			}// end for 2 repetare
		} // end for 1 repetare		
		// compar litere introduse de la tastatura cu cu literele din cuvantul secret
		comparare_cuvinte(cuvantul_secret, cuvant, lungime_cs, dim);			
	}// end for contorizare incercari
}

void clrscreen()
{
    system("@cls||clear");
}
