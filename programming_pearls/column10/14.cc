#include <stdio.h>
#include <algorithm>
#include <assert.h>

using namespace std;


/* Two-way partitioning */
void qsort3(int x[], int n)
{ 
  int i, j;
  int t;
  if (n <= 1)
    return;
  t = x[0];
  i = 0;
  j = n;
  for (;;) {
    do i++; while (i <= n - 1 && x[i] < t);
    do j--; while (x[j] > t);
    if (i > j)
      break;
    swap(x[i], x[j]);
  }
  swap(x[0], x[j]);
  qsort3(x, j);
  qsort3(x + j + 1, n - j - 1);
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
  qsort3(x, n);
  verify(x, n);
  return 0;
}
