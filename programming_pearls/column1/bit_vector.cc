#include <stdio.h>
#include <assert.h>

#define BITSPERWORD 32
#define SHIFT 5
#define MASK 0x1F
#define N 10000000

int a[1 + N/BITSPERWORD];

void set(int i) {
  a[i>>SHIFT] |= (1 << (i & MASK));
}

void clr(int i) {
  a[i>>SHIFT] &= ~(1 << (i & MASK));
}

int test(int i) {
  return a[i>>SHIFT] & (1 << (i & MASK));
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
