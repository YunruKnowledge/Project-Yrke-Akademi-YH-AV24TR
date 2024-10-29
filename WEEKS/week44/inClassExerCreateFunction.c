#include <stdio.h>

	#define MAX 30

	void printTheInt(char string[]);
	int sumReturn(int x, int y);
	int squareOf(int x);	
	int averageCalc(int firN, int secN, int thiN);
	int primeChecker(int x);
	char stringFunction(int ch);



	int main(void){
		//The printf function
		char theInput[MAX];


		printf("Write a name max %i characters.\n", MAX);
		scanf(" %s", theInput);

		printTheInt(theInput);

		//sumReturn.
		int num1 = 0;
		int num2 = 0;
		printf("Write the num1:\n");
		scanf(" %i", &num1);
		printf("Write the num2:\n");
		scanf(" %i", &num2);

		int sum = sumReturn(num1,num2);
		printf("%i\n", sum);

		//The square return function
		int num3 = 0;
		printf("Write the a num to get square of it:\n");
		scanf(" %i", &num3);
		squareOf(num3);
		int result = squareOf(num3);
		printf("%i", result);

		int firN = 0;
		int secN = 0;
		int thiN = 0;
		printf("Write the num for 1st out of 3 to get average:\n");
		scanf(" %i", &firN);
		printf("Write the num for 2nd to get average:\n");
		scanf(" %i", &secN);
		printf("Write the num for 3rd to get average:\n");
		scanf(" %i", &thiN);

		int average = averageCalc(firN,secN,thiN);
		printf("%i\n", average);
		
//Prime check
		int numX = 0;
		printf("Write a num to check if its a primeNumber:\n");
		scanf(" %i\n", &numX);
		primeChecker(numX);

//string function
		int ch = 0;
		stringFunction(ch);

		return 0;
	}

	char stringFunction(int ch){
		while((ch = getchar()) != '\n'){
			putchar(ch);
		}
	}

	int averageCalc(int firN, int secN, int thiN){
		int total = firN + secN + thiN;
		int average = total/3;
		return average;
	}

	int squareOf(int x){
		int result = x*x;
		return result;
	}
	
	int primeChecker(int x){
		if(x == 2 || x == 3 || x == 5 || x == 7 || x == 11 || 
        x == 13 || x == 17 || x == 19 || x == 23 || x == 29 || 
        x == 31 || x == 37 || x == 41 || x == 43 || x == 47 || 
        x == 53 || x == 59 || x == 61 || x == 67 || x == 71 || 
        x == 73 || x == 79 || x == 83 || x == 89 || x == 97 || x == 269){
			printf("Yep, you prompted an prime number: %i\n", x);
		}else{
			printf(" %i is in fact NOT a prime number!\n", x);
		}
	}

	int sumReturn(int x, int y){
		int sum;
		sum = x + y;
		return sum;
	}

	void printTheInt(char string[]){
	printf("\nThe output; %s\n", string);
	}

