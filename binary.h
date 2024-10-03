#ifndef BinaryLib
#define BinaryLib

void toBinary(int num){
    if (num == 0){
        printf("%d", num);
        return;
    }

    int binaryNum[4];
    int i = 0;

    while (num > 0) {
        binaryNum[i++] = num % 2;
        num /= 2;
    }

    //printf("%ld \n", (16 - sizeof(binaryNum)));
    printf("Binary answer: ");
    for (int k = 0; k <= (4 - sizeof(binaryNum)); k--)
    {
        printf("0");
    }

    for (int j = i-1; j >= 0; j--) {
        printf("%d",binaryNum[j]);  
    }
}

void binarySubstraction(int numA, int numB){
    while (numB != 0)
    {
        int resoult = (~numA) & numB;

        numA = numA ^ numB;
        numB = resoult << 1;
    }

    printf("Decimal answer: %d \n", numA - numB);
    toBinary(numA);
}
#endif