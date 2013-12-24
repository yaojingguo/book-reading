#include <stdio.h>

struct addition {
  int l;
  int u;
  int v;
};

void slice_add(int x[], struct addition opts[], int n)
{
  int *p = new int[n + 1];
  int *cum = p + 1;
  for (int i = 0; i < n; i++) {
    cum[opts[i].l - 1] -= opts[i].v;
    cum[opts[i].u] += opts[i].v;
  }

  for (int i = n - 1; i >= 0; i--) {
    x[i] = x[i + 1] + cum[i];
  }
    
  delete [] p;
}

void info(int x[], int n)
{
  for (int i = 0; i < n; i++)
    printf("%d ", x[i]);
  printf("\n");
}

void test1()
{
  int x[7] = {0}; 
  struct addition opts[] = {{0, 2, 7}, {2, 4, 8}, 
                            {1, 3, 1}, {2, 3, 7}, 
                            {1, 2, -1}, {3, 5, 2}};
  int n = 6;
  slice_add(x, opts, n);  
  info(x, n);
}

void test2()
{
  int x[3] = {0};
  struct addition opts[] = {{0, 1, 2}, {0, 0, 10}};
  int n = 2;
  slice_add(x, opts, n);
  info(x, n);
}

int main(int argc, const char *argv[]) 
{
  // The last item is a holder
  test1();
  test2();
  return 0;
}
