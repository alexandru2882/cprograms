// programul va printa primele x numere prime
// FACUT programul va citi nr x si va spune daca este prim
// va printa numerele prime aflate intre x si y

int number1, number2, prime;
int i, j, k = 0;
int mod;
char raspuns[3];

int verificareNumarPrim(int);

int arataNumerePrime(int, int);
int checkIfPrime();	
int interval_prim();
// MAIN
int interval_prim()
{	
	//while(1){
		//introducere numar
		printf("Introdu un interval de 2 numere pentru a gasi toate numerele prime aflate intre aceste limite!\n ");
		
		printf("Introdu primul numar: ");
		scanf("\n%d", &number1);
		
		printf("si al doilea numar: ");
		scanf("\n%d", &number2);
		
		if (number1>number2){
			number1=number1-number2; //8-2=6
			number2=number1+number2; //6+2=8
			number1=number2-number1; //8-6=2
		} else if(number1==number2){
			printf("Numerele sunt egale. Introdu te rog numere diferite.\n");
			exit(1);
		}
		//afisare toate numerele prime pana la numar
		arataNumerePrime(number1, number2);
		
		printf("\nApasa CTRL+C pentru a iesi.\n\n");
	//}
	return 0;
}


// definire functii
// primeste o valoare si verifica daca numarul e prim
int verificareNumarPrim(int number2)
{	
	j = 0;
	for(i=2; i<=number2/2; i++)
	{
		if((number2%i)==0)
		{	
			j=1;
			break;
		}
	}
	return j;
}

// printeaza toate numerele prime de la 1 pana la o anumita valoare
int arataNumerePrime(int number1, int number2)
{	
	printf("Numerele prime de la %d la %d sunt:\n\n", number1, number2);
	for(k=number1; k<=number2; k++)
	{
		prime = verificareNumarPrim(k);
		
		if(prime==0)
		{
		printf("Numarul %d\n", k);
		} else {
		continue;
		//printf("Numarul %d nu este prim\n", k);
		}
	}
}


