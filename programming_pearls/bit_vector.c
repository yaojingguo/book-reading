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
  printf("result: %d", test(10));
  // assert(test(10) == 1);
}

int main(int argc, const char *argv[]) 
{
  test_bit_vector();  
  return 0;
}
