#ifndef MODULE_EX241120
#define MODULE_EX241120

/**
 * @brief Sorts an int array in ascending order.
 * 
 * @param _int_array 
 * @param _size 
 */
void intSorterASC(int *_int_array, const int _size);

/**
 * @brief Read through and see if intergers of array are ascending,
 * if not return 0.
 *
 * @param _int_array
 * @param _size
 * @return int - `1` if true, `0` if false.
 */
int intArrayCheck(const int *_int_array, const int _size);

#endif