#include <stdio.h>

//read a num in the range of 0 to 255.
//convert to binary
//print the binary to the console
//while the the users num is more than 255, ask again.
//

int main(void){
int n = 8;
	unsigned char binary[n];

	int usrNum = 0;
	printf("write a number in range of 0-255:\n");
	scanf(" %i", &usrNum);

	//8421
	if(usrNum > 255){
		printf("The entered number is more than 255, enter a lower number.\n");
		// continue;
	}

	for (int i = 0; i < n; i++){
		binary[i] = (usrNum  % 2);
		usrNum = (usrNum / 2);
	}

	for (int geto = sizeof(binary) - 1; geto >= 0; geto--){
		printf(" %i ", binary[geto]);
	}//
}
