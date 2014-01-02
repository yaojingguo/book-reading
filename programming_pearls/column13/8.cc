#include <stdio.h>
#include <assert.h>

class IntSetBitVec {
  private:
    enum { BITSPERWORD = 32, SHIFT = 5, MASK = 0x1F };
    int n, hi, *x, nentry;
    void set(int i)  {        x[i>>SHIFT] |=  (1<<(i & MASK)); }
    void clr(int i)  {        x[i>>SHIFT] &= ~(1<<(i & MASK)); }
    int  test(int i) { return x[i>>SHIFT] &   (1<<(i & MASK)); }
  public:
    IntSetBitVec(int maxelements, int maxval)
    {
      hi = maxval;
      nentry = 1 + hi/BITSPERWORD;
      x = new int[nentry];
      for (int i = 0; i < nentry; i++)
        x[i] = 0;
      n = 0;
    }
    int size() { return n; }
    void insert(int t)
    { 
      if (test(t))
        return;
      set(t);
      n++;
    }
    void report(int *v)
    { 
      int i, j, k;
      k = 0;
      for (i = 0; i < nentry; i++)
        for (j = 0; j < BITSPERWORD; j++)
          if (x[i] & (1<<j))
            v[k++] = 32 * i + j;
    }
};

void test()
{
  IntSetBitVec S(10, 100);
  assert(S.size() == 0);
  S.insert(0);
  S.insert(1);
  assert(S.size() == 2);
  S.insert(78);
  assert(S.size() == 3);
  int* v = new int[3];
  S.report(v);
  for (int i = 0; i < 3; i++)
    printf("%d ", v[i]);
  printf("\n");
  delete [] v;
}

int main(int argc, const char *argv[]) 
{
  test();
  return 0;
}
