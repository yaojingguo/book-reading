#include <stdio.h>

unsigned char table[] = {0x7D, 0x50, 0x37, 0x57, 0x5A,
                         0x4F, 0x6F, 0x54, 0x7F, 0x5E};

void display(unsigned short n)
{
  if (n < 10) {
    printf("%1X", table[n]);
    return;
  }
  display(n / 10);
  printf("%1X", table[n % 10]);
}

int main(int argc, const char *argv[]) 
{
  display(100);
  return 0;
}
