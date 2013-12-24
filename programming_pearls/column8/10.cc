#include <map>
#include <iostream>
#include <algorithm>

using namespace std;


// return (i, j) s.t. A[i] + ... + A[j] is nearest to value c
pair<int, int> nearest_to_c(int t, int n, int A[]) {
  map<int, int> bst;
  bst[0] = -1;
  // barriers
  bst[-int(1e9)] = -2;
  bst[int(1e9)] = n;

  int sum = 0, start, end, ret = t;
  for (int i = 0; i < n; ++i) {
    sum += A[i];
    // it->first >= sum-c, and with the minimal value in bst
    map<int, int>::iterator it = bst.lower_bound(sum - t);
    int tmp = -(sum - t - it->first);
    if (tmp < ret) {
      ret = tmp;
      start = it->second + 1;
      end = i;
    }

    --it;
    // it->first < sum-c, and with the maximal value in bst
    tmp = sum - t - it->first;
    if (tmp < ret) {
      ret = tmp;
      start = it->second + 1;
      end = i;
    }

    bst[sum] = i;
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
