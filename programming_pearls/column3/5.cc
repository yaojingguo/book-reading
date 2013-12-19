#include <stdio.h>
#include <string.h>

#define N 2
const char *suffixes[2] = {"cinh", "cin"};


void hypen(const char* w, char* hypened)
{
  const char* s;
  int i, j, len, prefix;
  len = strlen(w);

  for (i = 0; i < N; i++) {
    for (j = 0, s = suffixes[i]; 
         s[j] != '\0' && w[len - 1 - j] == s[j]; 
         j++);
    if (s[j] == '\0') {
      prefix = len - j;
      strncat(hypened, w, prefix);
      strncat(hypened, "-", 1);
      strncat(hypened, w + prefix, j);
      return;
    }
  }
}

int main(int argc, const char *argv[]) 
{
  char buf[100];
  const char *words[] = {"ethnic", "clinic"};
  for (int i = 0; i < 2; i++) {
    buf[0] = '\0';
    hypen(words[i], buf);
    printf("%s => %s\n", words[i], buf);
  }
  return 0;
}
