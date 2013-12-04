#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <set>
#include <assert.h>
#include <string.h>

#define N 2000

#define BITSPERWORD 32
#define SHIFT 5
#define MASK 0x1F
#define SIZE (1 + N/BITSPERWORD)

int b[SIZE];
int from[SIZE];
int to[SIZE];
int top = 0;

void setup(int i)
{
  if (from[i] < top && to[from[i]] == i) 
    return;
  b[i] = 0;
  from[i] = top;
  to[top] = i;
  top++;
}

void set(int i) {
  int idx = i>>SHIFT;
  setup(idx);
  b[idx] |= (1 << (i & MASK));
}

void clr(int i) {
  int idx = i>>SHIFT;
  setup(idx);
  b[idx] &= ~(1 << (i & MASK));
}

int test(int i) {
  int idx = i>>SHIFT;
  setup(idx);
  return b[idx] & (1 << (i & MASK));
}

int test_bit_vector()
{
  // Since b is in data section, its elements will be initialized to 0. The 
  // following code to scramble the contents of array b.
  for (int i = 0; i < SIZE; i++)
    b[i] = 0xFFFFFFFF;

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
