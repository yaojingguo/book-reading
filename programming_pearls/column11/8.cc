#include <algorithm>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

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

void genshuf1(int m, int n)
{
  int i, j;
  int *x = new int[n];
  for (i = 0; i < n; i++)
    x[i] = i;
  for (i = 0; i < m; i++) {
    j = randint(i, n - 1);
    swap(x[i], x[j]);
  }
  for (i = 0; i < m; i++)
    printf("%d ", x[i]);
  printf("\n");
  delete [] x;
}

void genshuf2(int m, int n)
{
  int i;
  int *x = new int[m];
  for (i = 0; i < m; i++)
    x[i] = randint(0, n - 1);
  sort(x, x + m);
  for (i = 0; i < m; i++)
    printf("%d ", x[i]);
  printf("\n");
  delete [] x;
}

void genshuf3(int m, int n)
{
  int i;
  for (i = 0; i < m; i++)
    printf("%d ", randint(0, n - 1));
  printf("\n");
}

int main(int argc, const char *argv[]) 
{
  srand(getpid());
  genshuf1(10, 100);
  genshuf2(10, 5);
  genshuf3(10, 5);
  return 0;
}
