#include <map>
#include <iostream>
#include <algorithm>
#include <limits.h>

using namespace std;

// Return i and j with A[i..j]
pair<int, int> nearest_to_c(int t, int n, int A[]) {
  map<int, int> bst;
  bst[0] = -1;
  // barriers assume that no prefix sum is equal to INT_MAX or INT_MIN
  bst[INT_MIN] = -1;
  bst[INT_MAX] = n;

  int presum, subsum, i, j, start, end;
  int closest;
  bool unset;
  map<int, int>::iterator it;
  unset = true;
  for (i = 0; i < n; ++i) {
    presum += A[i];
    for (it = bst.lower_bound(presum - t), j = 0; j < 2; --it, j++) {
      if (it->first == -1 or it->first == n) 
        continue;
      subsum = presum - it->first;
      if (unset || abs(closest - t) > abs(subsum - t)) {
        closest = subsum;
        start = it->second + 1;
        end = i;
        unset = false;
      }
    }
    bst[presum] = i;
  }
  return make_pair(start, end);
}

// demo
int main() {
  int A[] = {10, 20, 30, 30, 20, 10, 10, 20};
  int t;
  cin >> t;
  pair<int, int> ans = nearest_to_c(t, 8, A);
  cout << ans.first << ' ' << ans.second << endl;
  return 0;
}
