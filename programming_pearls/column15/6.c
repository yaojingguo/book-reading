#include <stdlib.h>
#include <string.h>
#include <stdio.h>

struct suffix {
  int i;
  char* p;
};

int suffixcmp(const void *p, const void *q)
{   
  return strcmp(((suffix*) p)->p, ((suffix*) q)->p);
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
#define D '#'
char c[MAXN];
suffix a[MAXN];

// Compute longest common substring
// Input: string1#string2
int main()
{   
  int i, ch, n = 0, maxi, maxlen = -1, d;
  while ((ch = getchar()) != EOF) {
    a[n].p = &c[n];
    c[n++] = ch;
  }
  c[n] = 0;
  for (i = 0; i < n; i++)
    a[i].i = i;
  for (i = 0; i < n; i++)
    if (c[i] == D) {
      d = i;
      break;
    }
  qsort(a, n, sizeof(suffix), suffixcmp);
  for (i = 0; i < n-M; i++) {
    if (a[i].i < d && a[i+M].i < d) continue;
    if (a[i].i > d && a[i+M].i > d) continue;
    if (comlen(a[i].p, a[i+M].p) > maxlen) {
      maxlen = comlen(a[i].p, a[i+M].p);
      maxi = i;
    }
  }
  printf("%.*s\n", maxlen, a[maxi].p);
  return 0;
}
