#include <stdio.h>


//global scope
//global declaration
double x;
void my_function();
void my_other_function();


//global definiton
int main() //does not need a global declaration
{
    //local scope
    //local declaration
    double y;
    double z;

    //global definition
    x = 0.0; //global

    //local definiton
    y = 0.0; //local
    z = 0.0; //local

    printf("----------------------------------------\n");
    printf("main\n");
    printf("----------------------------------------\n");
    printf("global x = %.7lf\n", x);
    printf("local y = %.7lf\n", y);
    printf("local z = %.7lf\n", z);

    my_function();

    printf("----------------------------------------\n");
    printf("after my_function\n");
    printf("----------------------------------------\n");
    printf("global x = %.7lf\n", x);
    printf("local y = %.7lf\n", y);
    printf("local z = %.7lf\n", z);

    my_other_function();

    printf("----------------------------------------\n");
    printf("after my_other_function\n");
    printf("----------------------------------------\n");
    printf("global x = %.7lf\n", x);
    printf("local y = %.7lf\n", y);
    printf("local z = %.7lf\n", z);

    {
        //inner local scope
        //inner local declaration
        double y;

        //inner local definition
        y = 3.0; //inner local

        z = 3.0; //outer local

        printf("----------------------------------------\n");
        printf("inside inner local scope\n");
        printf("----------------------------------------\n");
        printf("global x = %.7lf\n", x);
        printf("inner local y = %.7lf\n", y);
        printf("outer local z = %.7lf\n", z);
    }

    printf("----------------------------------------\n");
    printf("after inner local scope\n");
    printf("----------------------------------------\n");
    printf("global x = %.7lf\n", x);
    printf("local y = %.7lf\n", y);
    printf("local z = %.7lf\n", z);

    printf("----------------------------------------\n");
    printf("endprogram\n");
    printf("----------------------------------------\n");
    return 0;
}


//global definiton
void my_function()
{
    //local scope
    //local declaration
    double y;

    x = 1.0; //global

    //local definition
    y = 1.0; //local
    
    printf("----------------------------------------\n");
    printf("inside my_function\n");
    printf("----------------------------------------\n");
    printf("global x = %.7lf\n", x);
    printf("local y = %.7lf\n", y);
}

//global definiton
void my_other_function()
{
    //local scope
    //local declaration
    double x;
    double y;

    //local definition
    x = 2.0; //local
    y = 2.0; //local

    printf("----------------------------------------\n");
    printf("inside my_other_function\n");
    printf("----------------------------------------\n");
    printf("local x = %.7lf\n", x);
    printf("local y = %.7lf\n", y);
}