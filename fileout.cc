#include<iostream>
#include<cstdio>     
using namespace std;
int main()
{
    FILE *fp;
    fp = fopen("writeoutput.txt", "w");
    /*fputs("The first line of writing to the text file.\n", fp);
    fputs("The second line.\n", fp);*/
    for(int i=1;i<=369;i++)
    fprintf(fp,"(\"deer (%d)\")\n,", i);
    fclose(fp);
    return 0;
}


