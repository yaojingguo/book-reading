#include <stdio.h>
#include <algorithm>


using namespace std;

int max3(int a, int b, int c)
{
  return max(max(a, b), c);
}

struct max_sum {
  int pre;
  int sub;
  int suf;
};

struct max_sum maxsum(int x[], int l, int u, int presums[])
{
  struct max_sum cur;
  if (l > u) {
    cur.pre = 0; 
    cur.sub = 0;
    cur.suf = 0;
    return cur;
  }
  if (l == u) {
    int t = max(0, x[l]);
    cur.pre = t;
    cur.sub = t;
    cur.suf = t;
    return cur;
  }
  int m = (l + u) / 2;
  struct max_sum left = maxsum(x, l, m, presums);
  struct max_sum right = maxsum(x, m + 1, u, presums);
  cur.sub = max3(left.sub, left.suf + right.pre, right.sub);
  cur.pre = max(left.pre, presums[m] + presums[l - 1] + right.pre);
  cur.suf = max(right.suf, presums[u] + presums[m] + left.suf);
  return cur;
}

int maxsum(int x[], int n)
{
  int* ptr = new int[n + 1];
  int* presums = ptr + 1;
  presums[-1] = 0;
  for (int i = 0; i < n; i++)
    presums[i] = presums[i-1] + x[i];
  delete [] ptr;
}

int main(int argc, const char *argv[]) 
{
  int x[] = {13 ,3 ,25, 20, 3, 16, 23, 18, 20, 7, 12, 5, 22, 15, 4, 7};
  maxsum(x, 16);
  return 0;
}
