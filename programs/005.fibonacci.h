int limita, rezultat, first, second;
int i;
int seria_fibonacci_f(int);

int seria_fibonacci(){
	limita = rezultat = first = second = 0;
	printf("Acest program afiseaza seria fibonacci formata din x numere.\n");
	printf("Cate cifre vrei sa aiba seria fibonacci? ");
	scanf("%i", &limita);
	//TODO de ce limita nu e un numar ci e adresa?
	printf("Limita e: %i\n", limita);
	// verificare pentru valoarea 0
	if(limita == 0){
	printf("EROARE. Introdu un numar mai mare ca 0.");
	exit(1);
	// verificare pentru numar negativ
	} else if(limita <= 0){
	printf("EROARE. Numarul trebuie sa fie pozitiv.");
	exit(1);
	// verificare pentru numarul 1
	} else if (limita == 1){
	printf("0 ");
	exit(1);
	// verificare pentru numarul 2
	} else if (limita == 2){
	printf("0 1 ");
	exit(1);
	}

	
	seria_fibonacci_f(limita);
	return 0;
}

// arata primele x numere din seria fibonacci
int seria_fibonacci_f(int limita){
	limita = limita - 3;
	first = 1, second = 1;
	printf("0 ");
	printf("%i ", first);
	printf("%i ", second);
	for(i=1; i<=limita; i++)
	{
		rezultat = first+second; //1+2=3
		first = second; // 2
		second = rezultat; // 3
		printf("%i ", rezultat);
	}
}
