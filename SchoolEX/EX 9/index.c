#include "../../Librarys/sortArray.h"
#include "../../Librarys/colors.h"

#define BUFFER 10

int main(void)
{
    int arr[BUFFER] = {6, 5, 0, 10, 4, 7, 13, 87, 65};
    int *arrPointer = arr;

    sortArray(arrPointer, BUFFER, ascending);

    if (checkArrayAscending(arrPointer, BUFFER))
    {
        (void)ShowSuccessMessage("Array is sorted correctly! \n");
    }
    else
    {
        (void)ShowErrorMessage("Array is not sorted correctly! \n");
    }

    return 0;
}