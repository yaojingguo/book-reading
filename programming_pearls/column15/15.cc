#include <stdio.h>
#include <stdlib.h>
using namespace std;

#define MAXN 5000000
char c[MAXN];

int bigrand()
{
  return RAND_MAX * rand() + rand();
}

int randint(int l, int u)
{
  int mod = u - l + 1;
  int r = bigrand() % mod;
  if (r < 0) r += mod;
  return l + r;
}

int main(int argc, const char *argv[]) 
{
  int n = 0, ch, i, j, max;
  while ((ch = getchar()) != EOF) 
    c[n++] = ch;
  c[n] = 0;
  i = randint(0, n - 1);
  putchar(c[i]);
  for (max = 100; max > 0; max--) {
    i = randint(0, n - 1); 
    for (j = i; c[j] != c[i]; j++) 
      ;
    if (j >= n - 1)
      break;
    i = j + 1;
    putchar(c[i]);
  }
  putchar('\n');
  return 0;
}
