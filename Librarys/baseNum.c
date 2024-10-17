int binaryRead(char input[], int verbal)
{
    int decimalTotal = 0;
    if (verbal)
        printf("DEBUG - decimal start: %d\n", decimalTotal);
    if (verbal)
        printf("DEBUG - strlen input length: %u\n", strlen(input));

    for (size_t i = 0; i < strlen(input); i++)
    {
        int digit = input[i] - '0';
        if (digit != 0 && digit != 1)
        {
            printf("Invalid, 0 and 1 only.\n");
            if (verbal)
                printf("BEDUG - ERROR - Bit: %d at position %d\n", digit, i);
            return 0;
        }

        int power = strlen(input) - i - 1;
        int value = digit * (1 << power);
        decimalTotal += value;
        if (verbal)
            printf("DEBUG - Bit: %d at position %d contributes: %d\n", digit, i, value);
    }
    return decimalTotal;
}

int hexToNum(char hex)
{
    if (hex <= '9' && hex >= '0')
        return hex - '0';
    else if (hex >= 'A' && hex <= 'F')
        return hex - 'A' + 10;
    else if (hex >= 'a' && hex <= 'f')
        return hex - 'a' + 10;
    else
        return -1;
}

int hexadecimalRead(char input[], int verbal)
{
    int decimalTotal = 0;
    int length = strlen(input);
    if (verbal)
        printf("DEBUG - decimal start: %d\n", decimalTotal);
    if (verbal)
        printf("DEBUG - strlen input length: %i\n", length);

    for (int i = 0; i < length; i++)
    {
        int value = hexToNum(input[i]);
        if (value == -1)
        {
            printf("Invalid hex character: %c at digit %d\n", input[i], i + 1);
            if (verbal)
                printf("DEBUG - ERROR - Invalid hex character: %c at position %d\n", input[i], i);
            return 0;
        }

        int power = length - i - 1;
        decimalTotal += value * (1 << (4 * power));
        if (verbal)
            printf("DEBUG - Hex: %c (decimal %d) at position %d contributes: %d\n", input[i], value, i, value * (1 << (4 * power)));
    }

    return decimalTotal;
}