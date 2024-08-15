#include <stdio.h>
#include <stdlib.h>


int main()
{
    //stack
    //variables hold values (size depends on type)
    int i = 0; //integer constant 0 is a rvalue
    char c = 'a'; //character constant 'a' is a rvalue
    double x = 1.0; //floating constant 1.0 is a rvalue
    //pointers hold addresses (8 byte values for 64-bit operating system)
    //* operator for pointer declaration
    char *cp = NULL; //char pointer = pointer pointing to an address of a char
    double *dp = NULL; //double pointer = pointer pointing to an address of a double
    //[] operator for array declaration
    char s[] = "abc"; //string = char array => decays into char pointer
    //STRING LITERAL "abc" = {'a', 'b', 'c', '\0'} IS A LVALUE
    double a[] = {1.0, 2.0, 3.0, 4.0}; //double array => decays into double pointer


    //& operator for variable address
    //[] operator for pointer dereferencing at array index
    printf("-----------------------------\n");
    printf("addresses on stack\n");
    printf("-----------------------------\n");
    printf("address &c : %p value c : %c\n", &c, c);
    printf("address &x : %p value x : %.7lf\n", &x, x);
    printf("address s : %p values :", s);
    for (i=0; i<4; i++) { printf(" s[%d]=%c", i, s[i]); }
    printf("\n");
    printf("address a : %p values :", a);
    for (i=0; i<4; i++) { printf(" a[%d]=%.7lf", i, a[i]); }
    printf("\n");


    //& and sizeof operator DO NOT decay arrays into pointers
    //& operator for array address
    //sizeof operator for array size
    printf("address &s : %p\n", &s);
    printf("address &a : %p\n", &a);
    printf("sizeof(s) = %d bytes\n", sizeof(s));
    printf("sizeof(a) = %d bytes\n", sizeof(a));
    //& operator for pointer address
    //sizeof operator for pointer size
    //64-bit operating system pointers store 8 bytes
    printf("address &cp : %p\n", &cp);
    printf("address &dp : %p\n", &dp);
    printf("sizeof(cp) = %d bytes\n", sizeof(cp));
    printf("sizeof(dp) = %d bytes\n", sizeof(dp));


    //* operator for pointer dereferencing
    //[] operator for pointer dereferencing at array index
    printf("-----------------------------\n");
    printf("pointers to addresses on stack\n");
    printf("-----------------------------\n");
    cp = &c;
    dp = &x;
    printf("address cp : %p value *cp : %c\n", cp, *cp);
    printf("address dp : %p value *dp : %.7lf\n", dp, *dp);
    //passing array => decays into pointer
    cp = s;
    dp = a;
    printf("address cp : %p values :", cp);
    for (i=0; i<4; i++) { printf(" cp[%d]=%c", i, cp[i]); }
    printf("\n");
    printf("address dp : %p values :", dp);
    for (i=0; i<4; i++) { printf(" dp[%d]=%.7lf", i, dp[i]); }
    printf("\n");


    //heap
    //dynamic memory allocation
    printf("-----------------------------\n");
    printf("pointers to addresses on heap\n");
    printf("-----------------------------\n");
    cp = (char *)malloc(4*sizeof(char)); //allocating
    printf("allocating\n");
    dp = (double *)malloc(4*sizeof(double)); //allocating
    printf("allocating\n");
    for (i=0; i<4; i++) {
        cp[i] = s[i];
        dp[i] = a[i];
    }
    printf("address cp : %p values :", cp);
    for (i=0; i<4; i++) { printf(" cp[%d]=%c", i, cp[i]); }
    printf("\n");
    printf("address dp : %p values :", dp);
    for (i=0; i<4; i++) { printf(" dp[%d]=%.7lf", i, dp[i]); }
    printf("\n");

    
    //garbage collection
    free(cp); //deallocating
    printf("deallocating\n");
    cp = NULL;
    free(dp); //deallocating
    printf("deallocating\n");
    dp = NULL;


    printf("-----------------------------\n");
    printf("endprogram\n");
    printf("-----------------------------\n");
    return 0;
}