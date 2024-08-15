/*
Header files are used to store external declarations of globals for multiple source files.
Every global must be externally declared only once in only one header file.
*/


/*
keyword: extern
An external declaration of a global references the existence of the global stored in another source file.
*/


//global declarations for all source files with #include "10_header.h"
extern int global_int; //global externally declared in one header file
void int_print_global_function(int value); //global function externally declared in one header file
int static_int_increment_global_function(); //global function externally declared in one header file