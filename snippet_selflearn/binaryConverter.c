#include <stdio.h>
#include <string.h>


int binaryRead(char input[], int verbal)
{
    int decimalTotal = 0;
    if (verbal)
        printf("DEBUG - decimal start: %d\n", decimalTotal);
    if (verbal)
        printf("DEBUG - strlen input length: %zu\n", strlen(input));

    for (int i = 0; i < strlen(input); i++)
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

int hexToNum(char hex, int verbal)
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
        int value = hexToNum(input[i], verbal);
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

int main()
{
    printf("Select a binary type. (Write a number.) \n");
    printf("1. 2 Bits - (00)\n");
    printf("2. 4 Bits - (0000)\n");
    printf("3. Byte - 8 bits - (00000000)\n");
    printf("4. Hexadecimal - 1 Byte - 0x(00)\n");
    printf("5. Hexadecimal - 2 Bytes - 0x(0000)\n");
    printf("6. Hexadecimal - 4 Bytes - 0x(00000000)\n");
    printf("7. DEBUG MODE.\n");

    int inputChoice;
    int debugger = 0;
    int baseMulti;
    scanf("%d", &inputChoice);

    if (inputChoice == 7)
    {
        debugger = 1;
        printf("*** DEBUGGER MODE ACTIVATED. ***\n");
        printf("Select a binary type. (7 removed.) \n");
        scanf("%d", &inputChoice);
    }

    if (inputChoice == 1)
    {
        char input[3];
        printf("Input your bits\n");
        printf("[NUMBER]x2 (xx)\n");
        printf("0b");
        scanf("%2s", &input);

        if (strlen(input) < 2)
            printf("WARNING - INPUT IS SHORTER THAN EXPECTED, RAN WITH [%zu] DIGITS.\n", strlen(input));
        printf("%d\n", binaryRead(input, debugger));
    }
    if (inputChoice == 2)
    {
        char input[5];
        printf("Input your bits\n");
        printf("[FILL]x4 (xxxx)\n");
        printf("0b");
        scanf("%4s", &input);

        if (strlen(input) < 4)
            printf("WARNING - INPUT IS SHORTER THAN EXPECTED, RAN WITH [%zu] DIGITS.\n", strlen(input));
        printf("%d\n", binaryRead(input, debugger));
    }
    if (inputChoice == 3)
    {
        char input[9];
        printf("Input your bits\n");
        printf("[NUMBER]x8 (xxxxxxxx)\n");
        printf("0b");
        scanf("%8s", &input);

        if (strlen(input) < 8)
            printf("WARNING - INPUT IS SHORTER THAN EXPECTED, RAN WITH [%zu] DIGITS.\n", strlen(input));
        printf("%d\n", binaryRead(input, debugger));
    }

    if (inputChoice == 4)
    {
        char input[3];
        printf("Input your hex\n");
        printf("[NUMBER]x2 (xx)\n");
        printf("0x");
        scanf("%2s", &input);

        if (strlen(input) < 2)
            printf("WARNING - INPUT IS SHORTER THAN EXPECTED, RAN WITH [%zu] DIGITS.\n", strlen(input));
        printf("%d\n", hexadecimalRead(input, debugger));
    }
    if (inputChoice == 5)
    {
        char input[5];
        printf("Input your hex\n");
        printf("[NUMBER]x4 (xxxx)\n");
        printf("0x");
        scanf("%4s", &input);

        if (strlen(input) < 4)
            printf("WARNING - INPUT IS SHORTER THAN EXPECTED, RAN WITH [%zu] DIGITS.\n", strlen(input));
        printf("%d\n", hexadecimalRead(input, debugger));
    }
    if (inputChoice == 6)
    {
        char input[9];
        printf("Input your hex\n");
        printf("[NUMBER]x8 (xxxxxxxx)\n");
        printf("0x");
        scanf("%8s", &input);

        if (strlen(input) < 8)
            printf("WARNING - INPUT IS SHORTER THAN EXPECTED, RAN WITH [%zu] DIGITS.\n", strlen(input));
        printf("%u\n", hexadecimalRead(input, debugger)); // unsigned output
    }
}

// 0.0 - 0.5 Low 0 False TTL
// 2.0 - 5.0 High 1 True TTL

// 0.0 - 0.8 Low 0 False CMOS
// 2.0 - 3.3 High 1 True CMOS

// NOT - AND - OR - XOR - () - NAND - NOR - XNOR
