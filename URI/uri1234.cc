#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;
int main()
{


    char line[50];
    int danca;
    while(cin.getline(line,50))
    {
        danca=0;
        for(int i=0; i<50; i++)
        {

            if(line[i]=='\0') break;
            if(danca == 0)
            {
                if(line[i] >= 97)
                {
                    printf("%c",line[i]-32);
                    danca = 1;
                }
                else if(line[i] == 32)
                {
                    printf("%c",line[i]);
                }
                else
                {
                    printf("%c",line[i]);
                    danca = 1;
                }
            }
            else
            {
                if(line[i] >= 97)
                {
                    printf("%c",line[i]);
                    danca = 0;
                    }
                else if(line[i] == 32)
                {
                    printf("%c",line[i]);
                }
                else
                {
                    printf("%c",line[i] + 32);
                    danca = 0;
                }
            }
        }
        printf("\n");
    }

    return 0;

}




