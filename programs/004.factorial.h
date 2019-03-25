//programul citeste un nr de la tastatura si calculeaza numarul factorial
int i, numar, produs_f = 1;

int numar_factorial();

int numar_factorial(){
	printf("Introdu un numar: ");
	scanf("%d", &numar);
	//TODO verific daca nr e negativ sau 0
	for(i=1; i<=numar; i++){
		produs_f=i*produs_f;
	}
	printf("%d factorial este: %d\n\n", numar, produs_f);
	return 0;
}
