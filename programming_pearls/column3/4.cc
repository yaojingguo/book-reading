#include <stdio.h>
#include <assert.h>

#define TRUE  1
#define FALSE 0

const char *month_names[] = {"January", "February", "March", "April", "May", "June", 
  "July", "August", "September", "October", "November", "December"};

//                   1   2   3   4   5   6   7   8   9   10  11  12
int months[][12] = {{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
                    {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}};

int years[] = {365, 366};

struct Date {
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

// Days in a year
int days_in_year(const Date& a)
{
  int cnt, i;
  int leap;
  leap = is_leap(a.year);
  for (i = 0, cnt = 0; i < a.month - 1; i++)
    cnt += months[leap][i];
  cnt += a.day;
  return cnt;
}

int days_between(const Date& a, const Date& b)
{
  int cnt = 0;
  for (int y = a.year; y < b.year; y++)
    cnt += years[is_leap(y)];
  cnt += days_in_year(b);
  cnt -= days_in_year(a);
  return cnt;
}

int weekday(const Date& a)
{
  int days = months[is_leap(a.year)][a.month - 1];
  const Date base = {2013, 12, 1};
  int base_days = days_in_year(base);
  printf("base_days: %d\n", base_days);
  int diff = days_between(base, a);
}

void calendar(int year, int month)
{
  int i;
  printf("       %d\n"
         "      %s\n"
         "====================", year, month_names[month - 1]);
  for (i = 0; i < months[is_leap(year)][month - 1]; i++) {
    if (i % 7 == 0) printf("\n");
    printf("%-3d", i + 1);
  }
  printf("\n");
}

void test_days() 
{
  Date a1 = {2012, 3, 1};
  assert(days_in_year(a1) == 61);
  Date a2 = {2013, 2, 10};
  assert(days_in_year(a2) == 41);
  assert(days_between(a1, a2) == 346);
  Date b1 = {2013, 12, 17};
  Date b2 = {2013, 12, 18};
  assert(days_between(b1, b2) == 1);
}

void test_weekday()
{
  Date today = {2013, 12, 19};
  weekday(today);
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
  // test_calendar();
  test_days();
  test_weekday();
  return 0;
}
