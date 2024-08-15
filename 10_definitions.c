#include <stdio.h> //system header file
#include "10_declarations.h" //user-defined header file


/*
Every global must be defined only once in only one source file.
*/


//global definitons for all source files with #include "10_header.h"
int global_int = 0; //global defined in one source file

void int_print_global_function(int value) //global function defined in one source file
{
    printf("%16d\n", value);
}

int static_int_increment_global_function() //global function defined in one source fle
{
    static int static_local_int = 0;

    static_local_int++;

    return static_local_int;
}