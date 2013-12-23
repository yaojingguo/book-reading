#include <stdio.h>
#include <stdlib.h>

int nearest_to_zero(int x[], int n, int m)
{
  if (n < m) return -1;
  int closest = 0x7FFFFFFF;
  int s = 0;
  int idx = -1;
  for (int i = -1; i < m; i++)
    s += x[i];
  for (int i = 0; i < n - m; i++) {
    s = s + x[i + m] - x[i - 1];
    if (abs(closest) > abs(s)) {
      closest = s;
      idx = i;
    }
  }
  return idx;
}

void verify(int x[], int n, int m)
{
  int idx = nearest_to_zero(x, n, m);
  printf("idx: %d\n", idx);
  for (int i = idx; i <= idx + m; i++)
    printf("%d ", x[i]);
  printf("\n");
}


int main(int argc, const char *argv[]) 
{
  int a[] = {0, 1, 2, -8, 7, 3, -5, 9};
  int *x = a + 1;
  verify(x, 7, 2);
  verify(x, 7, 1);
  return 0;
}
