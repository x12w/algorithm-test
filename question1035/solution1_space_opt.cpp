#include <bits/stdc++.h>
#include <cstddef>
using namespace std;

class Solution {
public:
  int maxUncrossedLines(vector<int> &nums1, vector<int> &nums2) {
    auto smaller = (nums1.size() < nums2.size() ? &nums1 : &nums2),
         bigger = (nums1.size() < nums2.size() ? &nums2 : &nums1);
    vector<int> dp((*smaller).size() + 1, 0);
    int res = 0;

    for (const auto &ele : *bigger) {
      int tmp = dp[0];
      for (size_t index = 1; index < dp.size(); index++) {
        int prev = tmp;
        tmp = dp[index];
        if (ele == (*smaller)[index - 1]) {
          dp[index] = prev + 1;
        } else {
          dp[index] = max(dp[index - 1], dp[index]);
        }
        res = max(res, dp[index]);
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
