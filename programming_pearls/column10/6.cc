#include <stdio.h>
#include <algorithm>
#include <assert.h>

using namespace std;

void selection_sort(int x[], int n)
{
  int i, j, t;
  for (i = 0; i <= n - 2; i++) {
    t = i;
    for (j = i + 1; j <= n - 1; j++)
      if (x[t] > x[j])
        t = j;
    swap(x[t], x[i]);
  }
}

void shell_sort(int x[], int n)
{
  int h, i, j;
  for (h = 1; h < n; h = 3 * h + 1)
    ;
  for (;;) {
    h /= 3;
    if (h < 1) 
      break;
    for (i = h; i < n; i++)
      for (j = i; j >= h; j -=h) {
        if (x[j - h] < x[j])
          break;
        swap(x[j - h], x[j]);
      }
  }
}

void verify(int x[], int n)
{
  int i;
  for (i = 0; i <= n - 2; i++)
    assert(x[i] <= x[i + 1]);
}

void info(int x[], int n)
{
  for (int i = 0; i < n; i++)
    printf("%d ", x[i]);
  printf("\n");
}

void test_selection_sort()
{
  int x[] = {8, 1, 2, 6, 5, 3};
  int n = 6;
  selection_sort(x, n);
  verify(x, n);
}

void test_shell_sort()
{
  int x[] = {8, 1, 2, 6, 5, 3};
  int n = 6;
  shell_sort(x, n);
  verify(x, n);
}

int main(int argc, const char *argv[]) 
{
  test_selection_sort();
  test_shell_sort();
  return 0;
}
