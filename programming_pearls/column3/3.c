#include <stdio.h>
#include <assert.h>

#define N 100
char buf[N];

void banner(char *s)
{
  char c;
  int i, j, row, col, cnt, printed;

  i = 0;
  while (s[i] != '\0') {
    row = s[i++] - '0';
    cnt = 0;
    while (s[i] != '\n' && s[i] != '\0') {
      col = s[i++] - '0';
      c = s[i++];
      for (j = 0; j < col; j++) {
        printed = snprintf(buf + cnt, N - cnt, "%c", c == 'b' ? ' ' : c);
        assert(printed == 1);
        cnt += printed;
      }
    }
    for (j = 0; j < row; j++)
      printf("%s\n", buf);
    if (s[i] == '\n') {
      i++;
    }
  }
  printf("\n");
}

int main(int argc, const char *argv[]) 
{
  banner("39x\n"
         "63b3x3b\n"
         "39x");
  return 0;
}
