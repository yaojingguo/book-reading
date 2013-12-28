#include <stdio.h>
#include <assert.h>


int bit_count(unsigned v)
{
  int c;
  v = v - ((v >> 1) & 0x55555555);                    // reuse input as temporary
  v = (v & 0x33333333) + ((v >> 2) & 0x33333333);     // temp
  c = ((v + (v >> 4) & 0xF0F0F0F) * 0x1010101) >> 24; // count
  return c;
}

void test_bit_count()
{
  assert(bit_count(1) == 1);
  assert(bit_count(0) == 0);
  assert(bit_count(0xF) == 4);
  assert(bit_count(0xFF) == 8);
}

int main(int argc, const char *argv[]) 
{
  test_bit_count();
  return 0;
}
