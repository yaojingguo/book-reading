#include <map>
#include <stdio.h>
#include <algorithm>
#include <limits.h>

using namespace std;

#define IDX_LOW_BOUND -2

// Return [i..j] range of A
pair<int, int> nearest_to_c(int A[], int n, int t) {
  map<int, int> bst;
  int presum, subsum, closest, i, j, start, end;
  bool unset;
  map<int, int>::iterator it;

  bst[0] = -1;
  // Barriers. Assume that no prefix sum is equal to INT_MAX or INT_MIN.
  bst[INT_MIN] = IDX_LOW_BOUND;
  bst[INT_MAX] = n;
  unset = true;
  // This initial value is always overwritten afterwards.
  closest = 0; 
  presum = 0;
  for (i = 0; i < n; ++i) {
    presum += A[i];
    for (it = bst.lower_bound(presum - t), j = 0; j < 2; --it, j++) {
      if (it->first == INT_MAX || it->first == INT_MIN) 
        continue;
      subsum = presum - it->first;
      if (unset || abs(closest - t) > abs(subsum - t)) {
        closest = subsum;
        start = it->second + 1;
        end = i;
        if (closest - t == 0)
          goto ret;
        unset = false;
      }
    }
    bst[presum] = i;
  }
ret:
  return make_pair(start, end);
}

int main() {
  int A[] = {10, 20, 30, 30, 20, 10, 10, 20};
  int t;
  scanf("%d", &t);
  pair<int, int> ans = nearest_to_c(A, 8, t);
  printf("[%d:%d]\n", ans.first, ans.second);
  return 0;
}
