#include <stdio.h>


void terminal_log_char(char copy)
{
    printf("%16c\n", copy);
}

void terminal_log_int(int copy)
{
    printf("%16d\n", copy);
}

void terminal_log_double(double copy)
{
    printf("%16.7lf\n", copy);
}

void terminal_log_string(const char *ref)
{
    printf("%16s\n", ref);
}


int main()
{
    char c = 'A';
    int i = 1;
    double x = 3.14159265359;
    char s[] = "string literal"; //string = char array => decays into char pointer

    terminal_log_char(c); //lvalue
    terminal_log_char('A'); //RVALUE
    terminal_log_int(i); //lvalue
    terminal_log_int(1); //RVALUE
    terminal_log_double(x); //lvalue
    terminal_log_double(3.14159265359); //RVALUE
    terminal_log_string(s); //lvalue
    terminal_log_string("string literal"); //STRING LITERALS ARE LVALUES

    return 0;
}