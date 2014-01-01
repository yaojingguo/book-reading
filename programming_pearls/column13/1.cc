#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int bigrand()
{
  return RAND_MAX * rand() + rand();
}

int randint(int l, int u)
{
  int mod = u - l + 1;
  int r = bigrand() % mod;
  if (r < 0) r += mod;
  return l + r;
}

class IntSetArr {
  private:
    int n, *x;
  public:
    IntSetArr(int maxelements, int maxval)
    { 
      x = new int[1 + maxelements];
      n=0;
      x[0] = maxval; /* sentinel at x[n] */
    }
    int size() { return n; }
    void insert(int t)
    { 
      int i, j;
      for (i = 0; x[i] < t; i++)
        ;
      if (x[i] == t)
        return;
      for (j = n; j >= i; j--)
        x[j+1] = x[j];
      x[i] = t;
      n++;
    }
    void report(int *v)
    { 
      for (int i = 0; i < n; i++)
        v[i] = x[i];
    } 
};

void genfloyd(int m, int n)
{
  IntSetArr S(m, n);
  int i;
  for (i = n - m; i < n; i++) {
    int t = randint(0, i);
    int oldsize = S.size();
    S.insert(t);
    if (S.size() == oldsize)
      S.insert(i);
  }
  int* v = new int[m];
  S.report(v);
  for (i = 0; i < m; i++)
    printf("%d\n", v[i]);
  delete [] v;
}

void init()
{
  srand(getpid());
}

int main(int argc, const char *argv[]) 
{
  int m = atoi(argv[1]);
  int n = atoi(argv[2]);
  init();
  genfloyd(m, n);
  return 0;
}
