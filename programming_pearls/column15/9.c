#include <stdlib.h>
#include <string.h>
#include <stdio.h>

struct suffix {
  int i;
  char* p;
};

int suffixcmp(const void *p, const void *q)
{   
  return strcmp(((struct suffix*) p)->p, ((struct suffix*) q)->p);
}

int comlen(char *p, char *q)
{ 
  int i = 0;
  while (*p && (*p++ == *q++))
    i++;
  return i;
}

int copy(char dest[], const char src[])
{  
  int i;
  for (i = 0; src[i]; i++) 
    dest[i] = src[i];
  return i;
}

#define M 1
#define MAXN 5000000
char c[MAXN]; 
struct suffix a[MAXN];

int main(int argc, const char *argv[]) 
{
  const char* s1 = argv[1];
  const char* s2 = argv[2]; 
  int p = copy(c, s1);
  c[p] = 0;
  int N = p + 1 + copy(c + p + 1, s2);
  int i;
  for (i = 0; i < N; i++) {
    a[i].p = &c[i];
    a[i].i = i;
  }
  printf("c: %s\n", c);
  printf("c: %s\n", c + strlen(c) + 1);
  qsort(a, N, sizeof(struct suffix), suffixcmp);
  int maxlen = -1, maxi;
  for (i = 0; i < N-M; i++) {
    if (a[i].i < p && a[i+M].i < p) continue;
    if (a[i].i > p && a[i+M].i > p) continue;
    if (comlen(a[i].p, a[i+M].p) > maxlen) {
      maxlen = comlen(a[i].p, a[i+M].p);
      maxi = i;
    }
  }
  printf("%.*s\n", maxlen, a[maxi].p);
  return 0;
}
