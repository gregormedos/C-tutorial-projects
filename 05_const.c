#include <stdio.h>


int main()
{
    printf("-----------------------------\n");
    printf("variables\n");
    printf("-----------------------------\n");
    double x = 0.0; //value can be changed
    x = 1.0;
    printf("&x : %p x : %.7lf\n", &x, x);

    printf("-----------------------------\n");
    printf("constants\n");
    printf("-----------------------------\n");
    const double PI = 3.14159265359; //value cannot be changed
    printf("&PI : %p PI : %.7lf\n", &PI, PI);

    printf("-----------------------------\n");
    printf("pointers to variables\n");
    printf("-----------------------------\n");
    double *ptr1 = NULL; //points to any adress, can change the value, CANNOT POINT TO CONST
    ptr1 = &x;
    *ptr1 = 2.0;
    printf("ptr1 : %p *ptr1 : %.7lf\n", ptr1, *ptr1);

    printf("-----------------------------\n");
    printf("pointers to constants\n");
    printf("-----------------------------\n");
    const double *c_ptr2 = NULL; //points to any adress, cannot change the value, CAN POINT TO CONST
    c_ptr2 = &x;
    printf("c_ptr2 : %p *c_ptr2 : %.7lf\n", c_ptr2, *c_ptr2);
    c_ptr2 = &PI;
    printf("c_ptr2 : %p *c_ptr2 : %.7lf\n", c_ptr2, *c_ptr2);

    printf("-----------------------------\n");
    printf("constant pointers to variables\n");
    printf("-----------------------------\n");
    double *const PTR3 = &x; //cannot be changed, can change the value, CANNOT POINT TO CONST
    *PTR3 = 4.0;
    printf("PTR3 : %p *PTR3 : %.7lf\n", PTR3, *PTR3);

    printf("-----------------------------\n");
    printf("constant pointers to constants\n");
    printf("-----------------------------\n");
    const double *const c_PTR4 = &PI; //cannot be changed, cannot change the value, CAN POINT TO CONST
    printf("c_PTR4 : %p *c_PTR4 : %.7lf\n", c_PTR4, *c_PTR4);

    printf("-----------------------------\n");
    printf("endprogram\n");
    printf("-----------------------------\n");
    return 0;
}