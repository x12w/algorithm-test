#include <bits/stdc++.h>
#include <cstddef>
using namespace std;

class Solution {
public:
  int maxUncrossedLines(vector<int> &nums1, vector<int> &nums2) {
    vector<vector<int>> dp(nums1.size() + 1, vector<int>(nums2.size() + 1, 0));
    int res = 0;

    for (size_t index1 = 1; index1 <= nums1.size(); index1++) {
      for (size_t index2 = 1; index2 <= nums2.size(); index2++) {
        if (nums1[index1 - 1] == nums2[index2 - 1]) {
          dp[index1][index2] = dp[index1 - 1][index2 - 1] + 1;
          res = max(res, dp[index1][index2]);
          continue;
        }
        dp[index1][index2] =
            max(dp[index1][index2 - 1], dp[index1 - 1][index2]);
        res = max(res, dp[index1][index2]);
      }
    }

    return res;
  }
};

int main() {
  Solution s;
  vector<int> v1{1, 3, 7, 1, 7, 5}, v2{1, 9, 2, 5, 1};
  cout << s.maxUncrossedLines(v1, v2);
}
