#include <stdio.h>
#include "./lib/baseNum.c"

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
            printf("WARNING - INPUT IS SHORTER THAN EXPECTED, RAN WITH [%u] DIGITS.\n", strlen(input));
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
            printf("WARNING - INPUT IS SHORTER THAN EXPECTED, RAN WITH [%u] DIGITS.\n", strlen(input));
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
            printf("WARNING - INPUT IS SHORTER THAN EXPECTED, RAN WITH [%u] DIGITS.\n", strlen(input));
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
            printf("WARNING - INPUT IS SHORTER THAN EXPECTED, RAN WITH [%u] DIGITS.\n", strlen(input));
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
            printf("WARNING - INPUT IS SHORTER THAN EXPECTED, RAN WITH [%u] DIGITS.\n", strlen(input));
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
            printf("WARNING - INPUT IS SHORTER THAN EXPECTED, RAN WITH [%u] DIGITS.\n", strlen(input));
        printf("%u\n", hexadecimalRead(input, debugger)); // unsigned output
    }
}

// 0.0 - 0.5 Low 0 False TTL
// 2.0 - 5.0 High 1 True TTL

// 0.0 - 0.8 Low 0 False CMOS
// 2.0 - 3.3 High 1 True CMOS

// NOT - AND - OR - XOR - () - NAND - NOR - XNOR