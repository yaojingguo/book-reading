#include <algorithm>
#include <stdio.h>

using namespace std;

int bigrand()
{ 
  return RAND_MAX*rand() + rand();
}

/* [l, u] */
int randint(int l, int u)
{ 
  int mod = u-l+1;
  int r = bigrand() % mod;
  if (r < 0) r += mod;
  return l + r;
}

void genshuf(int m, int n)
{
  int i, j;
  int *x = new int[n];
  for (i = 0; i < n; i++)
    x[i] = i;
  for (i = 0; i < m; i++) {
    j = randint(i, n - 1);
    swap(x[i], x[j]);
  }
  for (int i = 0; i < m; i++)
    printf("%d ", x[i] + 1);
  printf("\n");
}

int main(int argc, const char *argv[]) 
{
  genshuf(10, 100);
  return 0;
}
