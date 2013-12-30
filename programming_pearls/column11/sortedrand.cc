/* Copyright (C) 1999 Lucent Technologies */
/* From 'Programming Pearls' by Jon Bentley */

/* sortedrand.cpp -- output m sorted random ints in U[0,n) */

#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

int bigrand()
{ 
  return RAND_MAX*rand() + rand();
}

/* [l, u] */
int randint(int l, int u)
{ 
  int mod = u-l+1;
  int r = bigrand() % mod;
  if (r < 0) r += mod;
  return l + r;
}

void genknuth(int m, int n)
{ 
  for (int i = 0; i < n; i++)
    /* select m of remaining n-i */
    if (randint(0, n-i-1) < m) {
      cout << i << "\n";
      if (--m == 0) break;
    }
}

void gensets(int m, int n)
{ 
  set<int> S;
  set<int>::iterator i;
  while (S.size() < m) {
    int t = randint(0, n-1);
    S.insert(t);
  }
  for (i = S.begin(); i != S.end(); ++i)
    cout << *i << "\n";
}

void genshuf(int m, int n)
{ 
  int i, j;
  int *x = new int[n];
  for (i = 0; i < n; i++)
    x[i] = i;
  for (i = 0; i < m; i++) {
    j = randint(i, n-1);
    int t = x[i]; x[i] = x[j]; x[j] = t;
  }
  sort(x, x+m);
  for (i = 0; i < m; i++)
    cout << x[i] << "\n";
}

void genfloyd(int m, int n)
{ 
  set<int> S;
  set<int>::iterator i;
  for (int j = n-m; j < n; j++) {
    int t = bigrand() % (j+1);
    if (S.find(t) == S.end())
      S.insert(t); // t not in S
    else
      S.insert(j); // t in S
  }
  for (i = S.begin(); i != S.end(); ++i)
    cout << *i << "\n";
}

int main(int argc, char *argv[])
{ 
  int m = atoi(argv[1]);
  int n = atoi(argv[2]);
  genknuth(m, n);
  return 0;
}
