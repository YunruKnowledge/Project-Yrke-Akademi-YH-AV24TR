#include <stdio.h>
#include <string.h>

int binaryRead(char input[], int verbal) {
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


int main()
{
    printf("Select a binary type. (Write a number.) \n");
    printf("1. 2 Bits - (00)\n");
    printf("2. 4 Bits - (0000)\n");
    printf("3. Byte - 8 bits - (00000000)\n");
    // printf("4. Hexadecimal - 1 Byte - 0x(00)\n");
    // printf("5. Hexadecimal - 2 Bytes - 0x(0000)\n");
    // printf("6. Hexadecimal - 4 Bytes - 0x(00000000)\n");
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
        scanf("%2s", &input);

        printf("%d\n", binaryRead(input, debugger));
    }
    if (inputChoice == 2)
    {
        char input[5];
        printf("Input your bits\n");
        printf("[FILL]x4 (xxxx)\n");
        scanf("%4s", &input);

        printf("%d\n", binaryRead(input, debugger));
    }
    if (inputChoice == 3)
    {
        char input[9];
        printf("Input your bits\n");
        printf("[NUMBER]x8 (xxxxxxxx)\n");
        scanf("%8s", &input);

        printf("%d\n", binaryRead(input, debugger));
    }
}

// 0.0 - 0.5 Low 0 False TTL
// 2.0 - 5.0 High 1 True TTL

// 0.0 - 0.8 Low 0 False CMOS
// 2.0 - 3.3 High 1 True CMOS

// NOT - AND - OR - XOR - () - NAND - NOR - XNOR