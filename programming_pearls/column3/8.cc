#include <stdio.h>

unsigned char table[] = {0x7D, 0x50, 0x37, 0x57, 0x5A,
                         0x4F, 0x6F, 0x54, 0x7F, 0x5E};

void _display(unsigned short n)
{
  if (n < 10) {
    printf("%1X", table[n]);
    return;
  }
  _display(n / 10);
  printf("%1X", table[n % 10]);
}

void display(unsigned short n)
{
  _display(n);
  printf("\n");
}

int main(int argc, const char *argv[]) 
{
  display(100);
  display(1);
  display(0);
  display(0xFFFF);
  return 0;
}
