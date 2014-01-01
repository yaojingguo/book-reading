#include <stdio.h>
#include <stack>
#include <algorithm>

using namespace std;

struct range {
  int l;
  int u;
};

void qsort(int a[], int l, int u)
{
  stack<range> st;
  int m, i;
  range r = {l, u};
  st.push(r);
  while (!st.empty()) {
    r = st.top();
    st.pop();
    l = r.l;
    u = r.u;
    if (l >= u)
      continue;
    m = l;
    for (i = l + 1; i <= u; i++) 
      if (a[i] < a[l])
        swap(a[++m], a[i]);
    swap(a[l], a[m]);
    if (m - 1 - l >= u - m - 1) {
      r.l = l; 
      r.u = m - 1;
      st.push(r);
      r.l = m + 1; 
      r.u = u;
      st.push(r);
    } else {
      r.l = m + 1; 
      r.u = u;
      st.push(r);
      r.l = l; 
      r.u = m - 1;
      st.push(r);
    }
  }
}

void sort(int a[], int n)
{
  qsort(a, 0, n - 1);
}

void info(int a[], int n)
{
  for (int i = 0; i < n; i++)
    printf("%d ", a[i]);
  printf("\n");
}

int main(int argc, const char *argv[]) 
{
  int a[] = {8, 1, 2, 6, 5, 3};
  int n = 6;
  sort(a, n);
  info(a, n);
  return 0;
}
