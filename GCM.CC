#include <stdio.h>

/* Standard C Function: Greatest Common Divisor */
int 
gcd ( int a, int b )
{
  int c;
  while ( a != 0 ) {
     c = a; a = b%a;  b = c;
  }
  return b;
}

/* Recursive Standard C Function: Greatest Common Divisor */
int 
gcdr ( int a, int b )
{
  if ( a==0 ) 
  	return b;
  return gcdr ( b%a, a );
}


int
main(void)
{
  int a,b,c;
  a = 12;
  b = 18;
  c = 24;

  printf("a=%d, b=%d, c=%d\n", a,b,c);

  printf("gcd(a,b)=gcd(%d,%d)=%d\n", a, b, gcd(a,b));
  printf("gcd(a,b)=gcdr(%d,%d)=%d\n", a, b, gcdr(a,b));

  printf("gcd(a,c)=gcd(%d,%d)=%d\n", a, c, gcd(a,c));
  printf("gcd(a,c)=gcdr(%d,%d)=%d\n", a, c, gcdr(a,c));

  printf("gcd(c,b)=gcd(%d,%d)=%d\n", c, b, gcd(c,b));
  printf("gcd(c,b)=gcdr(%d,%d)=%d\n", c, b, gcdr(c,b));

  printf("gcd(a,b,c)=gcd(%d,gcd(%d,%d))=%d\n", a, b, c, gcd(a,gcd(b,c)));
  printf("gcd(a,b,c)=gcdr(%d,gcdr(%d,%d))=%d\n", a, b, c, gcdr(a,gcdr(b,c)));

  return 0;
}
