//char str[]="madam";
int i, str_len;
char *str;
int palindrom();


int palindrom(){
	printf("Introdu un cuvant pentru a verifica daca e un palindrom: ");
	printf("\n");
	scanf("%s", &str);
	// duplic numarul pentru a-l putea afisa mai tarziu
	
	
	//printf("Cuvantul %s are %d litere.\n", str, str_len);
	
	for (i=0; i<strlen; i++)
	{
		str_len = strlen(str);
		str_len = str_len - i;
		printf("Yeees!\n");
		if (str[i] == str[str_len]){
			printf("Yeees!\n");
		}
	}
	
	//compar numarul de litere aflate la aceeasi pozitie cu numarul de litere din cuvant
	if (1){
		printf("Cuvantul %s e palindrom.", str);
	} else {
		printf("Cuvantul %s nu e palindrom.", str);
	}

	return 0;
}


