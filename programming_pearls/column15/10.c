#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>

int pstrcmp(const void *p, const void *q)
{   
  return strcmp(*((const char**) p), *((const char**) q)); 
}

int comlen(char *p, char *q)
{ 
  int i = 0;
  while (*p && (*p++ == *q++))
    i++;
  return i;
}

#define M 1
#define MAXN 5000000
char c[MAXN], *a[MAXN];

int main()
{   
  int i, ch, n = 0, pn = 0, maxi, maxlen = -1;
  while ((ch = getchar()) != EOF) {
    // a[n] = &c[n];
    c[n++] = ch;
  }
  c[n] = 0;
  bool seenboundary = true;
  for (i = 0; i < n; i++)
    if (isspace(c[i])) {
      seenboundary = true;
    } else {
      if (seenboundary) {
        a[pn++] = &c[i];
        seenboundary = false;
      }
    }

  qsort(a, pn, sizeof(char *), pstrcmp);
  for (i = 0; i < pn-M; i++)
    if (comlen(a[i], a[i+M]) > maxlen) {
      maxlen = comlen(a[i], a[i+M]);
      maxi = i;
    }
  printf("%.*s\n", maxlen, a[maxi]);
  return 0;
}
