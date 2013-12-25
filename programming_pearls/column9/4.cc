#include <stdio.h>

#define NMAX 10000
int x[NMAX];

#define maxmac(a, b)  ((a) > (b) ? (a) : (b))

int maxfun(int a, int b)
{
  return a > b ? a : b;
}

#define max maxmac

float arrmax(int n)
{
  if (n == 1)
    return x[0];
  else
    return max(x[n - 1], arrmax(n - 1));
}

void info(int n)
{
  for (int i = 0; i < n; i++)
    printf("%d ", x[i]);
  printf("\n");
}

int main(int argc, const char *argv[]) 
{
  int n = 100;
  for (int i = 0; i < n; i++)
    x[i] = n - i;
  info(n);
  int max = arrmax(n);
  printf("max: %d\n", max);
  return 0;
}
