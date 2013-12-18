#include <stdio.h>

void info(int i, float v)
{
  printf("a[%d] = %f\n", i, v);
}

// c[0...k]   = c_1...c_(k+1)
// a[0...k-1] = a1...a_k
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

void wo_array(float c1, float c2, float c3, float c4, float c5, float c6,
              float a1, float a2, float a3, float a4, float a5,
              int m)
{
  info(1, c1);
  info(2, c2);
  info(3, c3);
  info(4, c4);
  info(5, c5);
  float v;
  for (int i = 5; i < m; i++) {
    switch (i % 5) {
      case 0:
        v = c1 * a5 + c2 * a4 + c3 * a3 + c4 * a2 + c5 * a1 + c6;
        a1 = v;
        break;
      case 1:
        v = c1 * a1 + c2 * a5 + c3 * a4 + c4 * a3 + c5 * a2 + c6;
        a2 = v;
        break;
      case 2:
        v = c1 * a2 + c2 * a1 + c3 * a5 + c4 * a4 + c5 * a3 + c6;
        a3 = v;
        break;
      case 3:
        v = c1 * a3 + c2 * a2 + c3 * a1 + c4 * a5 + c5 * a4 + c6;
        a4 = v;
        break;
      case 4:
        v = c1 * a4 + c2 * a3 + c3 * a2 + c4 * a1 + c5 * a5 + c6;
        a5 = v;
        break;
    };
    info(i + 1, v);
  }
}

int main(int argc, const char *argv[]) 
{
  return 0;
}
