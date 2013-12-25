#include <stdio.h>
#include <assert.h>

#define BETWEEN(c, l, u) ((l) <= (c) && (c) <= (u))

int isupper(int c)
{
  return BETWEEN(c, 'A', 'Z');
}

int isdigit(int c)
{
  return BETWEEN(c, '0', '9');
}

int islower(int c)
{
  return BETWEEN(c, 'a', 'z');
}

int main(int argc, const char *argv[]) 
{
  assert(isdigit('9') == 1);
  assert(isdigit('-') == 0);
  assert(isupper('A') == 1);
  assert(isupper('@') == 0);
  assert(islower('s') == 1);
  assert(islower('*') == 0);
  return 0;
}
