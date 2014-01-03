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
  int data[][2] = {{6, 7}, {7, 7}, {10, 15}};

  // for (n = 6; n <= 7; n++) {
  for (int i = 0; i < 3; i++) {
    table = build_table(data[i][0]);
    info(table, data[i][1]);
    delete [] table;
  }
  return 0;
}
