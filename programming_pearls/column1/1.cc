#include <stdio.h>
#include <stdlib.h>

int intcomp(const void *x, const void *y)
{
  int *x_int = (int*) x;
  int *y_int = (int*) y;
  return *x_int - *y_int;
}

int a[1000000];
int main(int argc, const char *argv[]) 
{
  int i, n = 0; 
  while (scanf("%d", &a[n]) != EOF)
    n++;
  qsort(a, n, sizeof(int), intcomp);
  for (i = 0; i < n; i++)
    printf("%d\b", a[i]);
  return 0;
}
