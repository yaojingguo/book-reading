#include <stdio.h>
#include <assert.h>
#include <algorithm>

using namespace std;

// 3-way partitionning quicksort
// http://algs4.cs.princeton.edu/23quicksort/

void qsort(int x[], int l, int u)
{
  if (l >= u) return;
  int lt, gt, i, v;
  v = x[l];
  i = l;
  lt = l;
  gt = u;
  while (i <= gt) 
    if      (x[i] < v) swap(x[lt++], x[i++]);
    else if (x[i] > v) swap(x[gt--], x[i]);
    else               i++;
  qsort(x, l, lt - 1);
  qsort(x, gt + 1, u);
}

void verify(int x[], int n)
{
  for (int i = 0; i < n - 1; i++)
    assert(x[i] <= x[i + 1]);
}

int main(int argc, const char *argv[]) 
{
  int x[] = {8, 1, 2, 6, 8, 8, 5, 3};
  int n = 8;
  qsort(x, 0, n - 1);
  verify(x, n);
  return 0;
}
