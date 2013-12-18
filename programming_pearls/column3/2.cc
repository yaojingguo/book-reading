#include <stdio.h>

void info(int i, float v)
{
  printf("a[%d] = %f\n", i, v);
}

void w_array(float c[], float a[], int k, int m)
{
  for (int i = 0; i < k; i++)
    info(i + 1, a[i]);
  float v;
  for (int i = k; i < m; i++) {
    v = c[k];
    for (int j = 0; j < k; j++)
      v += c[j] * a[k - 1 - i % k];
    info(i + 1, v);
    a[i % k] = v;
  }
}

int main(int argc, const char *argv[]) 
{
  return 0;
}
