### Modularity.

- remote control example. You only see the outside, you don't see the insides. [ Some times we need to hide some code has to be hidden. ]

- keeps our program organized.
- 6k line of code.
- take time to compile.

Hell to work with.

- test the file. Alot to deal with {Dependencies...etc} 

``` Modularity solves these issues. {Update/maintain}   ```

- Work with modules.
- Hide implementations.
- Encapsulate some data/code. Give access but make it abstract(Dificult to understand).


### Modules

## Single instace module.
-   single set of data
use static fule scope objects.
## multi instance module.
- abstract data types and private.
- functions that are aailable for the user.
- Think like a user.
## INCOMPLETE DATA TYPE
- hidden in a header file => ```typdef struct data data_t;```

### abstract data type
``` #ifndef MODULE_H #define MODULE_H //forward declaration typedef strucct data data_t  #endif /* MODULE_H  */ ```

```Only pointers that point to incomplete type can be defined and passed around. 

### For private module, use STATIC in the sourceFile.c

- for file 2 to acccess static func in file 1, a func named func "sum", will use the static func. 

- sum => just to get the return value from the sstatic func and return it to the other(not sourceFile.c).

```!!! ADT = ABSTRACTION DATA TYPE

### IMPORTANT
=> Module cleanup functions {Create, Destroy}
- Needed for functions that use the heap(Take up memory space)

---

### !!! ``` gcc -c {To send them an encrypted file that they can work with but cannot see the code.}