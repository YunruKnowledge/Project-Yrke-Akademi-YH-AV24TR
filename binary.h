void toBinary(int num){
    if (num == 0){
        printf("%d", num);
        return;
    }

    int binaryNum[16];
    int i = 0;

    while (num > 0) {
        binaryNum[i++] = num % 2;
        num /= 2;
    }
    
    for (int j = i-1; j >= 0; j--) {
        printf("%d",binaryNum[j]);  
    }
}

void binaryCalculator(int numA, int numB){
    int binaryNumA[16], binaryNumB[16], resoult[16];
    int i = 0, k = 0;

    while (numA > 0) {
        binaryNumA[i++] = numA % 2;
        numA /= 2;
    }

    while (numB > 0) {
        binaryNumB[k++] = numB % 2;
        numB /= 2;
    }


    for (int j = i-1; j >= 0; j--) {
        resoult[j] = binaryNumA[j] - binaryNumB[j];
        printf("%d", resoult[j]);  
    }
}
