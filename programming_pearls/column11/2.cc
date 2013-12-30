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

void gen(int m, int n)
{
  int i, r;
  for (r = randint(0, n - 1), i = 0; i < m; i++) 
    printf("%d\n", (r + i) % m);
}

int main(int argc, const char *argv[]) 
{
  int m = atoi(argv[1]);
  int n = atoi(argv[2]);
  gen(m, n);
  return 0;
}
