#include <stdio.h>

#define TRUE  1
#define FALSE 0

char *month_names[] = {"January", "February", "March", "April", "May", "June", 
  "July", "August", "September", "October", "November", "December"};

//                   1   2   3   4   5   6   7   8   9   10  11  12
int months[][12] = {{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
                    {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}};

int years[] = {365, 366};

struct date {
  int year;
  int month;
  int day;
};

int is_leap(int year) 
{
  if (year % 400 == 0) return TRUE;
  if (year % 4 == 0 && year % 100 != 0) return TRUE;
  return FALSE;
}

// int days_in_year()
// {
//   int cnt, i;
//   for (i = 0, cnt = 0; i < 12; i++)
//     cnt += months[i];
// }

int days(struct date a, struct date b)
{
  int cnt;

  cnt = 0;

}

int weekday(struct date a)
{
  int days = months[is_leap(a.year)][a.month - 1];
}

void calendar(int year, int month)
{
  int i;
  printf("       %d\n"
         "      %s\n"
         // "Su Mo Tu We Th Fr Sa", year, month_names[month - 1]);
         "====================", year, month_names[month - 1]);
  for (i = 0; i < months[is_leap(year)][month - 1]; i++) {
    if (i % 7 == 0) printf("\n");
    printf("%-3d", i + 1);
  }
  printf("\n");
}

void test_calendar()
{
  calendar(2010, 2);
  calendar(2012, 2);
  calendar(2013, 11);
  calendar(2013, 12);
}

int main(int argc, const char *argv[]) 
{
  test_calendar();
  return 0;
}
