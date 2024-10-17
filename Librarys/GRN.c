int getRandomNumber(int min, int max) {
    unsigned int seed = time(0);
    int rd_num = rand_r(&seed) % (max - min + 1) + min;
    return rd_num;
}

int* getArrayOfRandomNumbers(int min, int max, int count) {
    if (count <= 0 || min >= max) return NULL;

    int* numbers = (int*)malloc(count * sizeof(int));
    if (!numbers) return NULL;

    srand(time(NULL));
    for (int i = 0; i < count; i++) {
        numbers[i] = min + rand() % (max - min);
    }
    return numbers;
}
