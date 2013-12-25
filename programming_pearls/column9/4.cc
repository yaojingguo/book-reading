#include <stdio.h>

#define NMAX 10000
int x[NMAX];

#define max(a, b)  ((a) > (b) ? (a) : (b))

float arrmax(int n)
{
  if (n == 1)
    return x[0];
  else
    return max(x[n - 1], arrmax(n - 1));
}

int main(int argc, const char *argv[]) 
{
  return 0;
}
