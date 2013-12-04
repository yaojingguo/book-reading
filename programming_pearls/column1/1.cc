#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <set>

using namespace std;

int intcomp(const void *x, const void *y)
{
  int *x_int = (int*) x;
  int *y_int = (int*) y;
  return *x_int - *y_int;
}

int a[1000000];
void qsort_sort()
{
  int i, n = 0; 
  while (scanf("%d", &a[n]) != EOF)
    n++;
  qsort(a, n, sizeof(int), intcomp);
  for (i = 0; i < n; i++)
    printf("%d\b", a[i]);
}

void set_sort()
{
  set<int> S;
  int i;
  set<int>::iterator j;
  while (cin >> i)
    S.insert(i);
  for (j = S.begin(); j != S.end(); ++i)
    cout << *j << endl;
}

int main(int argc, const char *argv[]) 
{
  return 0;
}
