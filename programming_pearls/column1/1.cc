#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <set>
#include <assert.h>

#define N 10000000

int intcomp(const void *x, const void *y)
{
  int *x_int = (int*) x;
  int *y_int = (int*) y;
  return *x_int - *y_int;
}

int a[N];
void qsort_sort()
{
  int i, n = 0; 
  while (scanf("%d", &a[n]) != EOF)
    n++;
  qsort(a, n, sizeof(int), intcomp);
  for (i = 0; i < n; i++)
    printf("%d\b", a[i]);
}

void set_sort()
{
  std::set<int> S;
  int i;
  std::set<int>::iterator j;
  while (std::cin >> i)
    S.insert(i);
  for (j = S.begin(); j != S.end(); ++i)
    std::cout << *j << std::endl;
}

#define BITSPERWORD 32
#define SHIFT 5
#define MASK 0x1F

int b[1 + N/BITSPERWORD];

void set(int i) {
  b[i>>SHIFT] |= (1 << (i & MASK));
}

void clr(int i) {
  b[i>>SHIFT] &= ~(1 << (i & MASK));
}

int test(int i) {
  return b[i>>SHIFT] & (1 << (i & MASK));
}

int test_bit_vector()
{
  set(10);
  assert(test(10) > 0);
  assert(test(9) == 0);
  assert(test(11) == 0);
  assert(test(1000) == 0);

  set(1000);
  assert(test(10) > 0);
  assert(test(1000) > 0);
  
  clr(10);
  clr(1000);
  assert(test(10) == 0);
  assert(test(1000) == 0);
}

int main(int argc, const char *argv[]) 
{
  test_bit_vector();
  return 0;
}
