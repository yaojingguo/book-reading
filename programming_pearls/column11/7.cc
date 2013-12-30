#include <stdio.h>
#include <algorithm>
#include <vector>

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

void comb(int m, int n, vector<bool>& set)
{
  if (m == 0) {
    for (int i = set.size() - 1; i >= 0; i--)
      if (set[i])
        printf("%d ", i + 1);
    printf("\n");
    return;
  }
  if (n == 0 || n < m)
    return;
  comb(m, n - 1, set);
  set[n - 1] = true;
  comb(m - 1, n - 1, set);
  set[n - 1] = false;
}

void c(int m, int n)
{
  vector<bool> set(n);
  comb(m, n, set); 
}

int main(int argc, const char *argv[]) 
{
  int m = atoi(argv[1]);
  int n = atoi(argv[2]);
  c(m, n);
  return 0;
}
