// if on external viewer (GitHub), view through code.
These are just notes, comes with invisible asterisks.

`volatile` declaration - type qualifier for variables always read from memory, remains untouched by compiler.
Public variables.

`restrict` declaration - pointer to pointers. (?)

`_Atomic` - can be read or modified without interrupt, can not be Array nor Function.  
<stdatomic.h>

`static` storage class - alive during lifetime of software, invisible/unaccessable by other files, always global variable.
Private variable.

`enum` type - interger object, define name to int, call name and return value, increments values by one each step.
enum [NAME] {a=1,b=5,c} // a=1 b=5 c=6
enum [NAME] [VAR_NAME] = [ENUM_VAL]; // calling enum.

> Literals, term for hard coded variables.
> Quotations, single char '', char array ""

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
