int getRandomNumber(int min, int max) {
    unsigned int seed = time(0);
    int rd_num = rand_r(&seed) % (max - min + 1) + min;
    return rd_num;
}

int* getArrayOfRandomNumbers(int min, int max, int count) {
    int* numbers = (int*)malloc(count * sizeof(int));

    unsigned int seed = time(0);
    for (int i = 0; i <= count; i++) {
        numbers[i] = min + rand_r(&seed) % (max - min);
    }
    return numbers;
}
