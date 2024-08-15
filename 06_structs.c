#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//Structures (Upper Case) consist of different data types called members (lower case)
typedef struct _MyStruct
{
    //member declaration
    char member2[16];   //16 * 1 bytes
    double member5;     //8 bytes
    int member4[3];     //3 * 4 bytes
    int member3;        //4 bytes
    char member1;       //1 byte
                        //7 bytes of padding
    //aligment of char   must be divisible by 1
    //aligment of int    must be divisible by 4
    //aligment of double must be divisible by 8
    //sizeof(MyStruct)   must be divisible by 8
    //sizeof(MyStruct) = 48 bytes
} MyStruct;


void MyStruct_printm(const MyStruct *Struct_ref)
{
    //-> operator for pointer dereferencing at member
    printf("%16c\n", Struct_ref->member1);
    printf("%16s\n", Struct_ref->member2);
    printf("%16d\n", Struct_ref->member3);
    for (int i=0; i<3; i++) {
        printf("%16d\n", Struct_ref->member4[i]);
    }
    printf("%16.7lf\n", Struct_ref->member5);
}

void MyStruct_setm(MyStruct *Struct_ref, char member1_arg, const char *member2_ref, int member3_arg, const int *member4_ref, double member5_arg)
{
    //-> operator for pointer dereferencing at member
    Struct_ref->member1 = member1_arg;
    strcpy(Struct_ref->member2, member2_ref);
    Struct_ref->member3 = member3_arg;
    for (int i=0; i<3; i++) {
        Struct_ref->member4[i] = member4_ref[i];
    }
    Struct_ref->member5 = member5_arg;
}


int main()
{
    int i = 0;
    char c = 'b';
    char string[16] = "spaghetti";
    int array[3] = {1,2,3};
    char *cptr = NULL;
    int *iptr = NULL;
    //every declaration of a Structure has its own declared members
    MyStruct Struct1;
    MyStruct Struct2;
    MyStruct *Structptr = NULL;


    printf("----------------------------------------\n");
    printf("sizeof(type)\n");
    printf("----------------------------------------\n");
    //sizeof(type)
    printf("sizeof(char) = %zu bytes\n", sizeof(char));
    printf("sizeof(short) = %zu bytes\n", sizeof(short));
    printf("sizeof(int) = %zu bytes\n", sizeof(int));
    printf("sizeof(long) = %zu bytes\n", sizeof(long)); //4 bytes in 64-bit operating system
    printf("sizeof(long long) = %zu bytes\n", sizeof(long long)); //8 bytes in 64-bit operating system
    printf("sizeof(float) = %zu bytes\n", sizeof(float));
    printf("sizeof(double) = %zu bytes\n", sizeof(double));
    printf("sizeof(MyStruct) = %zu bytes\n", sizeof(MyStruct));
    //all pointer types have the same size to store one adress
    //64-bit operating system pointers store 8 bytes
    printf("sizeof(char *) = %zu bytes\n", sizeof(char *));
    printf("sizeof(short *) = %zu bytes\n", sizeof(short *));
    printf("sizeof(int *) = %zu bytes\n", sizeof(int *));
    printf("sizeof(long) = %zu bytes\n", sizeof(long *));
    printf("sizeof(long long) = %zu bytes\n", sizeof(long long *));
    printf("sizeof(float *) = %zu bytes\n", sizeof(float *));
    printf("sizeof(double *) = %zu bytes\n", sizeof(double *));
    printf("sizeof(MyStruct *) = %zu bytes\n", sizeof(MyStruct *));


    //. operator for accessing members
    Struct1.member1 = 'a';
    strcpy(Struct1.member2, "string");
    Struct1.member3 = 0;
    Struct1.member4[0] = 0;
    Struct1.member4[1] = 1;
    Struct1.member4[2] = 2;
    Struct1.member5 = 1.0;
    //passing by adress
    MyStruct_setm(&Struct2, 'b', string, 1, array, 2.0);
    //dynamic memory allocation
    printf("----------------------------------------\n");
    printf("dynamic memory allocation\n");
    printf("----------------------------------------\n");
    cptr = (char *)malloc(16*sizeof(char)); //allocating
    printf("allocating %zu bytes\n", 16*sizeof(char));
    strcpy(cptr, "meatballs");
    iptr = (int *)malloc(3*sizeof(int)); //allocating
    printf("allocating %zu bytes\n", 3*sizeof(int));
    for (i=0; i<3; i++) {
        iptr[i] = i+2;
    }
    Structptr = (MyStruct *)malloc(sizeof(MyStruct)); //allocating
    printf("allocating %zu bytes\n", sizeof(MyStruct));
    //passing by pointer
    MyStruct_setm(Structptr, 'c', cptr, 2, iptr, 3.0);


    printf("----------------------------------------\n");
    printf("MyStruct Struct1 members\n");
    printf("----------------------------------------\n");
    //. operator for accessing members
    printf("%16c\n", Struct1.member1);
    printf("%16s\n", Struct1.member2);
    printf("%16d\n", Struct1.member3);
    for (i=0; i<3; i++) {
        printf("%16d\n", Struct1.member4[i]);
    }
    printf("%16.7lf\n", Struct1.member5);
    printf("----------------------------------------\n");
    printf("MyStruct Struct2 members\n");
    printf("----------------------------------------\n");
    //passing by adress
    MyStruct_printm(&Struct2);
    printf("----------------------------------------\n");
    printf("MyStruct *Structptr members\n");
    printf("----------------------------------------\n");
    //passing by pointer
    MyStruct_printm(Structptr);


    printf("----------------------------------------\n");
    printf("garbage collection\n");
    printf("----------------------------------------\n");
    free(cptr); //deallocating
    printf("deallocating %zu bytes\n", 16*sizeof(char));
    cptr = NULL;
    free(iptr); //deallocating
    printf("deallocating %zu bytes\n", 3*sizeof(int));
    iptr = NULL;
    free(Structptr); //deallocating
    printf("deallocating %zu bytes\n", sizeof(MyStruct));
    Structptr = NULL;


    printf("----------------------------------------\n");
    printf("endprogram\n");
    printf("----------------------------------------\n");
    return 0;
}