/*
Programul genereaza un meniu si permite rularea fiecarui proiect selectat
*/

/*
Fiecare proiect va fi savat intr-un fisier separat cu extensia .h si va contine
codul 
*/

// input output
#include <stdio.h>
// libraria standard 
#include <stdlib.h>
// fac operatii pe string
#include <string.h>
// alegere cuvinte random 
#include <time.h>

// aici se vor introduce proiectele
#include "programs/001.jocul_ghiceste.h"
#include "programs/002.vortex.h"
#include "programs/003.armstrong.h" 
#include "programs/004.factorial.h"
#include "programs/005.fibonacci.h"
#include "programs/006.gasire_nr_prime_in_interval.h"
#include "programs/007.bubble_sort.h"
#include "programs/008.palindrome_str_cmp_letter.h"




//elemente din meniu (numarul e generat automat)
char *elemente_meniu[] = { "",
// aici vor fi introduse intrarile in meniu
"Ghiceste cuvantul secret",
"Verifica daca un numar este numar Vortex",
"Afla daca un numar este numar Armstrong",
"Calculeaza factorialul unui numar",
"Calculeaza seria Fibonacci",
"Gaseste numerele prime dintr-un interval",
"Sorteaza cu Bubble sort",
"Afla daca un cuvant este palindrom"
};

// prototypes
void clrscr();
int ghiceste_cuvantul_secret();
int numar_vortex();
int numar_armstrong();
int numar_factorial();
int seria_fibonacci();
int interval_prim();
int bubble_sort();
int palindrom();
int meniu();

//MAIN
int main(){
	meniu();
	return 0;
}

//clears the screen
void clrscr()
{
    system("@cls||clear");
}

int meniu(){
	while(1) {
		int array_length_full;
		int array_length;
		int selected_number;
		int i;
		int menu_length_full;		
		int number_of_options = sizeof(elemente_meniu)/sizeof(elemente_meniu[0])-1;
		int *selectie[number_of_options];
		//number_of_options = menu_length_full;
		//printf("\nnumar elemente in array %i\n", number_of_options);
		for (i=0; i<=number_of_options; i++) {
			//numarul maxim de optiuni
			selectie[i] = i;
			//printf("I este %i\n", i);
			//printf("selectie[i] este %i\n", selectie[i]);
		}

		//dimensiunea reala a array-ului
		array_length_full = sizeof(selectie)/sizeof(selectie[0]);
		
		//printf("Size: %i\n", array_length_full);
		
		//permite afisarea corecta a maxim 99 elemente in meniu (primele 9 numere au 0 inaintea lor)
		for (i=1; i<=number_of_options; i++) {
			if (i<10)
			printf ("%d%d. %s\n", 0, i, elemente_meniu[i]);
			else
			printf ("%d. %s\n", i, elemente_meniu[i]);
		}

		printf ("\nAlege o optiune, apoi apasa tasta ENTER\nSau apasa CTRL+C pentru a iesi.\n");
		scanf ("%d", &selected_number);
		clrscr();
		//TODO  De ce imi returneaza 0 cand introduc 77?
		for (i=0; i<=number_of_options; i++) {
			//printf("i in for: %d\n", i);
			//verifica daca a fost introdusa o optiune invalida
			if (selected_number > number_of_options) {
				printf("Te rog selecteaza o optiune valida\n");
				break;
			} else
			 if (selected_number == i){
				//	printf("i in IF: %d\n\n", i);
				if (selected_number == 0){
					printf("Ai selectat 0. Te rog alege o optiune valida\n");
					break;
				} else if (selected_number == 1){
					jocul_ghiceste();
				} else if (selected_number == 2){
					numar_vortex();
				} else if (selected_number == 3){
					numar_armstrong();
				} else if (selected_number == 4){
					numar_factorial();
				} else if (selected_number == 5){
					seria_fibonacci();
				} else if (selected_number == 6){
					interval_prim();
				} else if (selected_number == 7){
					bubble_sort();
				} else if (selected_number == 8){
					palindrom();
				}
			} 
		}
	}
}

