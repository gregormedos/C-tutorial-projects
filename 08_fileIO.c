#include <stdio.h>


int main()
{
    //FILE pointer handles files
    FILE *fptr;


    fptr = fopen("filename.txt", "w");
    //fputc writes a character into a file
    fputc('A', fptr);
    //fputs writes a string into a file
    fputs(" string of characters\n", fptr);
    //fprintf writes a formatted string from data into a file
    fprintf(fptr, "integer %16d double %16.7lf double %16.7le\n", 1, 1.0, 3.14159265359);
    fclose(fptr);
    

    fptr = fopen("filename.txt", "r");
    char c;
    //fgetc reads a character from a file
    while ((c = fgetc(fptr)) != EOF) {
        printf("%c", c);
    }
    printf("\n");
    fclose(fptr);


    fptr = fopen("filename.txt", "r");
    char buff[255];
    //fgets reads a line as a string from a file
    fgets(buff, 255, fptr);
    printf("%s", buff);
    fgets(buff, 255, fptr);
    printf("%s", buff);
    int i;
    double x;
    double pi;
    printf("\n");
    fclose(fptr);
    //sscanf reads data from a formatted string
    sscanf(buff, "integer %d double %lf double %lf\n", &i, &x, &pi); //MUST USE %lf FOR DOUBLES
    printf("integer %16d double %16.7lf double %16.7le\n", i, x, pi);
    

    return 0;
}