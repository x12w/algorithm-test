#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int longestSubsequence(vector<int> &arr, int difference) {
    unordered_map<int, int> dp{};
    int res = 1;

    for (const auto &ele : arr) {

      dp[ele] = dp[ele - difference] + 1;

      res = max(res, dp[ele]);
    }

    return res;
  }
};

int main() {
  Solution s;
  vector<int> v{};
  cout << s.longestSubsequence(v, 1);
}
