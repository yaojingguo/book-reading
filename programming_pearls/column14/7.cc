#include <stdio.h>
#include <assert.h>

int log(unsigned n)
{
  assert(n > 0);
  int i = 0;
  while (n > 1) {
    n >>= 1;
    i++;
  }
  return i;
}

void build(int l, int u, int table[], int i)
{
  if (l > u) return;
  int m = (u - l) / 2 + l;
  printf("l: %d, u: %d, i: %d, m: %d\n", l, u, i, m);
  table[i] = m;
  build(l, m - 1, table, 2*i);
  build(m + 1, u, table, 2*i+1);
}

int* build_table(int n)
{
  int l = log(n);
  int size = 1 << (l+1);
  int* table = new int[size];
  for (int i = 1; i < size; i++)
    table[i] = -1;
  build(0, n - 1, table, 1);
  return table;
}

void info(int table[], int n)
{
  for (int i = 1; i <= n; i++)
    printf("%d ", table[i]);
  printf("\n");
}

int main(int argc, const char *argv[]) 
{
  int* table;
  int n;

  for (n = 6; n <= 6; n++) {
    table = build_table(n);
    info(table, 7);
    delete [] table;
  }
  return 0;
}
