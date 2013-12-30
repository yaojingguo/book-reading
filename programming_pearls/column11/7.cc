#include <stdio.h>
#include <algorithm>

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

void randselect(int m, int n)
{
  if (m > 0) {
    if (randint(0, n - 1) < m) {
      randselect(m - 1, n - 1);
      printf("%d\n", n - 1);
    } else
      randselect(m, n - 1);
  }
}

int main(int argc, const char *argv[]) 
{
  int m = atoi(argv[1]);
  int n = atoi(argv[2]);
  randselect(m, n);
  return 0;
}
