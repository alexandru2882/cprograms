/*
This program accepts any number (smaller than 2147483647) as a user input
and then adds all its digits together until there in only one digit left.
*/

//variable declaration section
unsigned long long int nr, temp_nr, divider; // max value (which can be added) in Dev-C++ compiler is: 2147483647
unsigned long int remainder, result, sum;
int number_of_digits;

//prototype declaration section
void welcome();
int read_number();
int count_digits(int);
int add_digits(int);
int numar_vortex();

// MAIN program
int numar_vortex()
{
	welcome();
	read_number();
	
	// prints the number of digits
	number_of_digits = count_digits(nr);
	printf("The number has %d digits.\n", number_of_digits);
	
	//this function returns the sum of all the digits
	add_digits(nr);
	
	// print the original number and then the result
	printf("\nYou entered: %d\n", temp_nr);
	printf("The sum of the digits is: %d\n\n\n", sum);
	
	return 0;
}
// end of MAIN


//function definition section

//prints a short descriptive message at the begining
void welcome()
{
	printf("Welcome!\n");
	printf("This program will ask you for an number and then will return\n");
	printf("the sum of its digits until the result is a one digit number.\n");
	printf("To exit press CTRL + C.\n\n");
}

//asks for user input
int read_number()
{
	// this function asks for a number from the user
	printf("Enter a number:\n");
	scanf("%d", &nr);
	//temp_nr: used to print the original number at the end of the program
	temp_nr = nr;
}

//gets the number of digits of the number
int count_digits(int num)
{
    if (num == 0) return 1;
    int n = 0;
    while(num) {
        num /= 10;
        n++;
    }
    return n;
}

//adds all the digits of nr until the result is a one digit number
int add_digits(int number)
{
	number_of_digits = count_digits(number);
	while (number_of_digits >=1 && number != 0){
		//gets the last digit
		remainder=number%10;
		
		//the result makes the sum of all the digits ultil there are none digits left		
		result += remainder;
	
		//gets the number without the last digit
		divider = number/10;

		//the new number will lack a last digit
		number=divider;
	
		//when all the digits have been added the sum will be exported
		if (number == 0){
			sum = result;
			result = 0;
			number_of_digits = count_digits(sum);
			//if sum is not a one digit number, its numbers will be added
			if(number_of_digits > 1){
				number = sum;
			}
		}
	}
	return sum;
}
