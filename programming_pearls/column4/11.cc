#include <stdio.h>
#include <assert.h>

#define MAXN 100
typedef unsigned DataType;

int n;
DataType x[MAXN];

// Return value instead of index. -1 means not-found.
int binarysearch(DataType x[], int n, DataType t)
{
  if (n < 1) return -1;
  int m = (n - 1) / 2;
  if (t == x[m]) 
    return x[m];
  else if (t > x[m])  
    return binarysearch(x + m + 1, n - (m + 1), t);
  else             
    return binarysearch(x, m, t);
}

int main(int argc, const char *argv[]) 
{
  n = 10;
  for (int i = 0; i < n; i++)
    x[i] = 10 * i;
  printf("%d\n", binarysearch(x, 10, 30));
  return 0;
}
