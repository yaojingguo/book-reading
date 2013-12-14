#include <string.h>
#include <stdio.h>
#include <assert.h>
#include <algorithm>

using namespace std;

int euclid_gcd(int a, int b)
{
  assert(a >= 0 && b >= 0);
  if (b == 0) return a;
  else        return euclid_gcd(b, a % b);
}

void swap(char x[], int a, int b, int m)
{
  for (int i = 0; i < m; i++)
    swap(x[a + i], x[b + i]);
}

void left_rotate(char* x, int rotdist)
{
  int i, gcd, n, j, k;
  char t;

  n = strlen(x);
  gcd = euclid_gcd(n, rotdist);
  for (i = 0; i < gcd; i++) {
    t = x[i];
    j = i;
    for (;;) {
      k = j + rotdist;
      if (k >= n) k -= n;
      if (k == i) break;
      x[j] = x[k];
      j = k;
    }
    x[j] = t;
  }
}

void left_rotate2(char* x, int rotdist)
{
  int n, i, j, p;

  n = strlen(x);
  if (rotdist == 0 || rotdist == n) return;
  i = p = rotdist;
  j = n - p;
  while (i != j) {
    // Loop Invariant:
    // x[0   ... p-i-1] in final position
    // x[p-i ... p-1]   = a (to be swapped with b)
    // x[p   ... p+j-1] = b (to be swapped with a)
    // x[p+j ... n-1] in final position
    if (i > j) {
      swap(x, p - i, p, j);
      i -= j;
    } else {
      swap(x, p -i, p + j - i, i);
      j -= i;
    }
  }
  swap(x, p - i, p, i);
}

void test_euclid_gcd()
{
  assert(euclid_gcd(4, 2) == 2);
}

void verify_rotate(void (*fp)(char*, int ))
{
  char x[] = "abcdefgh";
  fp(x, 3);
  assert(strcmp("defghabc", x) == 0);
}

void test_rotate()
{
  verify_rotate(left_rotate);
  verify_rotate(left_rotate2);
}

int main(int argc, const char *argv[]) 
{
  test_euclid_gcd();
  test_rotate();
  return 0;
}
