#include <stdio.h>
#include <stack>
#include <assert.h>
 
using namespace std;

bool even(int n)
{
  return (n & 1) == 0;
}

int exp(int x, int n)
{
  stack<int> st;
  while (n > 0) {
    st.push(n);
    if (even(n)) n /= 2;
    else         n -= 1;
  }
  st.push(0);

  int prev, cur, pow;
  while (!st.empty()) {
    cur = st.top();
    st.pop();
    if (cur == 0)             pow = 1;
    else if (cur == prev + 1) pow *= x;
    else                      pow *= pow;
    prev = cur;
  }
  return pow;
}

int exp2(int x, int n)
{
  int p, f;
  p = 1;
  f = x;
  while (n > 0) {
    if (n & 1) 
      p = p * f;
    n >>= 1;
    f *= f;
  }
  return p;
}

void verify_exp(int (*fp)(int, int))
{
  assert(fp(0, 0) == 1);
  assert(fp(3, 0) == 1);
  assert(fp(3, 1) == 3);
  assert(fp(3, 2) == 9);
  assert(fp(3, 4) == 81);
}

void test_exp()
{
  verify_exp(exp);
  verify_exp(exp2);
}

int main(int argc, const char *argv[]) 
{
  test_exp();
  return 0;
}
