#include <bits/stdc++.h>
#include <cstddef>
using namespace std;

class Solution {
public:
  int longestArithSeqLength(vector<int> &nums) {
    if (nums.size() < 2)
      return nums.size();
    vector<unordered_map<int, int>> dp(nums.size());
    int res = 0;
    for (size_t index1 = 0; index1 < nums.size(); index1++) {
      for (size_t index2 = 0; index2 < index1; index2++) {
        int diff = nums[index1] - nums[index2],
            prev = dp[index2].count(diff) ? dp[index2][diff] : 1;
        dp[index1][diff] = max(dp[index1][diff], prev + 1);
        res = max(res, dp[index1][diff]);
      }
    }
    return res;
  }
};

int main() {
  Solution s;
  vector<int> v{22, 8,  57, 41, 36, 46, 42, 28, 42, 14, 9,  43, 27, 51,
                0,  0,  38, 50, 31, 60, 29, 31, 20, 23, 37, 53, 27, 1,
                47, 42, 28, 31, 10, 35, 39, 12, 15, 6,  35, 31, 45, 21,
                30, 19, 5,  5,  4,  18, 38, 51, 10, 7,  20, 38, 28, 53,
                15, 55, 60, 56, 43, 48, 34, 53, 54, 55, 14, 9,  56, 52};
  cout << s.longestArithSeqLength(v);
}
