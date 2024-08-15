#include <stdio.h>
#include <limits.h>
#include <float.h>


int main()
{
    //declaration
//  char c8;
    //definition
//  c8 = 'c';
    //declaration and definition
    char c8 = 'c'; //c8 is a lvalue, character constant literal 'c' is a rvalue
    short i16 = (short)1; //i16 is a lvalue, integer constant literal 1 is a rvalue, type casting a short to an integer constant literal because there is no short constant literal
    i16 = SHRT_MAX; //preprocessor macro #define
    int i32 = 2; //i32 is a lvalue, integer constant literal 2 is a rvalue
    i32 = INT_MAX;
    long i32_old = 2L; //i32_old is a lvalue, long constant literal 2L is a rvalue
    i32_old = LONG_MAX; //32-bit operating system
    long long i64 = 3LL; //i64 is a lvalue, long long cosntant literal 3LL is a rvalue
    i64 = LONG_LONG_MAX; //64-bit operating system
    float f32 = 3.14159265359F; //f32 is a lvalue, float constant literal 3.14159265359F is a rvalue
    f32 = FLT_MAX;
    double f64 = 3.14159265359; //f64 is a lvalue, double constant literal 3.14159265359 is a rvalue
    f64 = DBL_MAX;

    printf("char c8 = %c\n", c8);
    printf("short i16 = %hd\n", i16);
    printf("int i32 = %d\n", i32);
    printf("long i32 = %ld\n", i32_old);
    printf("long long i64 = %lld\n", i64); //MUST USE %lld FOR LONG LONG
    printf("float f32 = %.16e\n", f32, f32);
    printf("double f64 = %.16le\n", f64, f64);

    return 0;
}