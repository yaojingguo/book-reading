#include <stdio.h>
#include <assert.h>

int binarysearch(int x[], int n, int t)
{
  int l, u, m, p;
  l = -1; u = n;
  while (l + 1 != u) {
    m = (u - l) / 2 + l;
    if (t > x[m])
      l = m;
    else 
      u = m;
  }
  p = u;
  if (p >= n || x[p] != t)
    p = -1;
  return p;
}

int main(int argc, const char *argv[]) 
{
  int x[] = {1, 2, 2, 4};
  assert(binarysearch(x, 4, 2) == 1);
  assert(binarysearch(x, 4, 4) == 3);
  assert(binarysearch(x, 4, 7) == -1);
  return 0;
}
