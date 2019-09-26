// ios::eof example
#include <fstream>  // std::ifstream
#include <iostream> // std::cout

int main()
{
  std::ifstream is("input.txt"); // open file
  char c;
  while (!is.eof())
  {
    is.get(c);
    std::cout << c;
  }
  return 0;
}