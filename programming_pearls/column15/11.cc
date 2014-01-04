#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

char x[5000000];

int main(int argc, const char *argv[]) 
{
  int i, ch, n, eqsofar, max, k = 1;
  char *p, *nextp, *q;
  srand(getpid());
  n = 0;
  while ((ch = getchar()) != EOF) 
    x[n++] = ch;
  x[n] = 0;
  p = x;
  for (max = 2000; max > 0; max--) {
    eqsofar = 0;
    for (q = x; q < x + n - k + 1; q++) {
      for (i = 0; i < k && p[i] == q[i]; i++)
        ;
      if (i == k)
        if (rand() % ++eqsofar == 0)
          nextp = q;
    }
    ch = nextp[k];
    if (ch == 0)
      break;
    putchar(ch);
    p = nextp + 1;
  }
  return 0;
}
