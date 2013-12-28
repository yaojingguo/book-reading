#include <stdio.h>
#include <stack>

using namespace std;

void qsort(int a[], int n)
{
}

void info(int a[], int n)
{
  for (int i = 0; i < n; i++)
    printf("%d ", a[i]);
  printf("\n");
}

int main(int argc, const char *argv[]) 
{
  int a[] = {8, 1, 2, 6, 5, 3};
  int n = 6;
  qsort(a, n);
  return 0;
}
