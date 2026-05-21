#include <bits/stdc++.h>
#include <cstddef>
#include <vector>
using namespace std;

// this algorithm's time complexity is O(n^2)
class Solution {
public:
  int findLongestChain(vector<vector<int>> &pairs) {
    sort(pairs.begin(), pairs.end(),
         [](vector<int> &v1, vector<int> &v2) { return v1[0] < v2[0]; });

    vector<int> dp(pairs.size());

    for (size_t dp_index = 0; dp_index < dp.size(); dp_index++) {
      int max_len = 0;
      for (size_t front_index = 0; front_index < dp_index; front_index++) {
        if (pairs[dp_index][0] > pairs[front_index][1]) {
          max_len = max(max_len, dp[front_index]);
        }
      }
      dp[dp_index] = max_len + 1;
    }
    return dp.back();
  }
};

int main() {
  Solution s;
  vector<vector<int>> pairs{{1, 2}, {4, 6}, {8, 9}};
  s.findLongestChain(pairs);
}
