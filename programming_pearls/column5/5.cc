#include <stdio.h>
#include <assert.h>

#define MAXN 100

typedef int DataType;

int n;
DataType x[MAXN];

int binarysearch(DataType t)
{
  int l, u, m;
  l = 0; 
  u = n - 1;
  while (l <= u) {
    m = (u - l) / 2 + l;
    assert((m - 1 < 0 || x[m - 1] < x[m]) && (m+1 >= n || x[m] <= x[m+1]));
    if (t > x[m])      l = m + 1;
    else if (t < x[m]) u = m - 1;
    else               return m;
  }
  return -1;
}

int main(int argc, const char *argv[]) 
{
  n = 10;
  for (int i = 0; i < n; i++)
    x[i] = 10 * i;
  assert(binarysearch(10) == 1);
  return 0;
}
