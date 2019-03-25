/*
	Name: Check for armstrong number
	Copyright: 2019
	Author: Alexandru Popovici
	Date: 18/03/19 20:39
	Description: 
	The user enters a number and the program checks whether that number is an armstrong number or not.
	An armstrong number is a number like 153, you raise all of its gigits to the power equal to the
	total number of digits, in our case 3, and then you add them to get the number. 
	1^3 + 5^3 + 3^3 = 1 + 125 + 27 = 153
*/


int i, j, k, number, power = 1, sum_a = 0, temp, last_digit, counter = 0;

int count_digits_a(int);
int digits_power_sum_a(int, int);
int check_armstrong(int, int);
int check_all_numbers(int);

int numar_armstrong();

int numar_armstrong(){

	printf("Press 1 to check a number \n");
	printf("Press 2 to check a series (enter the last number of the series) \n");
	scanf("%d", &temp);
	// nu merge sa calculeze
	if (temp == 1){
		printf("\nEnter a number: ");
		scanf("%d", &number);
		counter = count_digits_a(number);
		temp = digits_power_sum_a(number, counter);
		
		if (number == temp){
			printf("Congratulations! The number %d is an armstrong number!\n\n", number);
		}
		else {
			printf("The number %d isn't an armstrong number!\n\n", number);
		}
	} 
	else if (temp == 2){
		printf("\nEnter a number: ");
		scanf("%d", &number);
		check_all_numbers(number);
	} else {
		printf("Nu exista aceasta optiune.");
	}	
}

// finds the number of digits in the number
int count_digits_a(int n){
	while(n != 0){
		n = n/10;
		counter++;
	}
	return counter;
}

int digits_power_sum_a(int n, int c) {
	
	for (i=0; i<c; i++){
		last_digit = n%10;
		temp = n/10;
		n = temp;
		power=1;
		
		for (j=0; j<c; j++){
			if (last_digit == 0){
				power = 0;
				power = power + last_digit;
			} else {
				power = power * last_digit;
			}
		}
		sum_a = sum_a + power;
	}

	return sum_a;
}

int check_armstrong(int n, int c){
	if (n == digits_power_sum_a(n, c)){
		printf("Congratulations! The number %d is an armstrong number!\n", n);
	} 
}

int check_all_numbers(int n){
	for(k=1; k<=n; k++){
		sum_a = 0;
		counter = count_digits_a(k);
		check_armstrong(k, counter);
		counter = 0;
	}
}

