
#include <stdio.h>
#include <string.h>
char* appendCharToCharArray(char* array, char a)
{
    size_t len = strlen(array);

    char* ret = new char[len+2];

    strcpy(ret, array);
    ret[len] = a;
    ret[len+1] = '\0';

    return ret;
}
int main ()
{
    char a[]="";
    printf("Test= %s",appendCharToCharArray(a,'F'));
    char* s[]=new char[50];
    s=appendCharToCharArray(a,'F');


    return 0;


}
