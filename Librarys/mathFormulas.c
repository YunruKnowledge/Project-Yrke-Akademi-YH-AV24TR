int LCM(const int numOne, const int numTwo)
{
    int returnVal = 0;
    for (int i = 0; i < (sizeof(int) * 8); i++)
    {
        if (returnVal)
            break;
        for (int j = 0; j < (sizeof(int) * 8); j++)
        {
            if (numOne * i == numTwo * j)
                returnVal = numOne * i;
            else if (numOne * i < numTwo * j)
                break;
        }
    }

    return returnVal;
}

int GCD(const int numOne, const int numTwo)
{
    return (numOne * numTwo) / LCM(numOne, numTwo);
}