// if on external viewer (GitHub), view through code.
These are just notes, comes with invisible asterisks.

# Declarations / Classes

`volatile` declaration - type qualifier for variables always read from memory, remains untouched by compiler.
Public variables.

`restrict` declaration - pointer to pointers. (?)

`_Atomic` - can be read or modified without interrupt, can not be Array nor Function.  
<stdatomic.h>

`static` storage class - alive during lifetime of software, invisible/unaccessable by other files, always global variable.
Private variable.

# Types

`enum` type - interger object, define name to int, call name and return value, increments values by one each step.
enum [NAME] {a=1,b=5,c} // a=1 b=5 c=6
enum [NAME] [VAR_NAME] = [ENUM_VAL]; // calling enum.

`struct` data type - object class.
struct [NAME] {int [MEMBER_VALUE]:8; char [MEMBER_NAME][];} [OR_NAME_HERE]; // :8 meaning 8 bits.
struct [NAME] [VAR_NAME]; // call.

`union` data type - same as struct, but all member share value in memory. Allocates the highest bit/byte amount.
struct [NAME] {int [VALUE]; int [VALUE_2]}; struct [NAME] [VAR_NAME];
[VAR_NAME].[VALUE] = 4;
[VAR_NAME].[VALUE_2] = 6;
// log([VAR_NAME].[VALUE]) outputs 6

`([TYPE])[VAR]` type casting - changes/specifies type of variable. Truncates data.
float fl = 3.14; int fake_fl = (int)fl;
// log(fake_fl) outputs int of 3

`void` VOID O.O - ~~point of~~ no return, or sent to the void.
(void) || void [FUNCTION]

# Terms

`Postfix` & `Prefix` operator/expression (suffix, prefix).
int x = 1; 
// log(x++) outputs 1, then incremented to 2. 
// log(++x) decremented to 1, then outputs 1.

`Ternary operator` operator - if x then y else z.
x ? y : z;

`Literals` term - for hard coded variables.

`Single quote` & `Double quote` term - single char '', char array ""

`Type promotion` term - when casting a variable to have a bigger type.

# Misc.

`  MEMORY MAP  `
`| ENVIROMENT |` -> Args
`|   STACK    |` -> Temp/local variables/functions
`|   EMPTY    |` -> Remainder - used by HEAP & STACK
`|   HEAP     |` -> Dynamic misc. var/allocation
`|   BSS      |` -> Uninitialized data - Zero
`|   DATA     |` -> DS initialized data - Global / static variables
`|   TEXT     |` -> Binary code - Read only

> Free from memory using `free();`
int *p = (int *)malloc(sizeof(int)); // p points to adress.
free(p); // remove p pointer link, adress remains.
return; // end function.
