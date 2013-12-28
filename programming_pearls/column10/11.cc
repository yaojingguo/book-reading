#include <stdio.h>
#include <assert.h>

// 3-way partitionning quicksort
// http://algs4.cs.princeton.edu/23quicksort/

int qsort(int x[], int l, int u)
{
}

void verify(int x[], int n)
{
  for (int i = 0; i < n - 1; i++)
    assert(x[i] <= x[i + 1]);
}

int main(int argc, const char *argv[]) 
{
  int x[] = {8, 1, 2, 6, 5, 3};
  int n = 6;
  qsort(x, 0, n - 1);
  verify(x, n);
  return 0;
}
