// http://en.wikipedia.org/wiki/Collatz_conjecture
#include <stdio.h>

bool even(int x)
{
  return (x & 1) == 0;
}

void f(int x) {
  printf("x:\n");
  while (x != 1) {
    printf("  %d\n", x);
    if (even(x))
      x /= 2;
    else
      x = 3 * x + 1;
  }
}

int main(int argc, const char *argv[]) 
{
  f(2);
  f(7);
  return 0;
}
