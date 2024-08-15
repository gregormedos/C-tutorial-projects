#include "10_declarations.h" //user-defined header file


/*
Declaration informs the compiler that it exists and its storage and type.
Definition informs the compiler to allocate the storage.
*/


/*
A local is declared and defined inside a function between every invocation and is stored in the entirety of the invocation
A global is declared globally and is stored in the entirety of the program
*/


/*
keyword: static
A static global is stored only in the entirety of the source file in which it is declared and defined in.
A static local is declared and defined inside a function only once and is stored in the entirety of the program between all invocations
*/


static int static_global_int = 0; //static global declared and defined in one source file


int main()
{
    int_print_global_function(global_int);
    global_int = 1;
    int_print_global_function(global_int);
    int_print_global_function(static_global_int);
    static_global_int = 1;
    int_print_global_function(static_global_int);
    int_print_global_function(static_int_increment_global_function());
    int_print_global_function(static_int_increment_global_function());
    int_print_global_function(static_int_increment_global_function());

    return 0;
}