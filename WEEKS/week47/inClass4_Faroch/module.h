#ifndef MODULE_H 
#define MODULE_H
//to prevent multi inclusion

#define MODULE_BUFFSIZE 8//public identifier.


typedef struct human person_t;

void module_print_int(int x); //starts with modules name(convention).
void module_print_string(const char *str, int x);
void personDestroy(person_t *prsn);

#endif