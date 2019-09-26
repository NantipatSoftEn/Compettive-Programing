// ios::eof example
#include <fstream>  // std::ifstream
#include <iostream> // std::cout

int main()
{
    char s1[1000][20];

    int i = 0;

    while (!feof(stdin))
        fgets(s1[i++], 20, stdin);

    int j;
    for (j = 0; j < i; j++)
        printf("%s\n", s1[j]);
}