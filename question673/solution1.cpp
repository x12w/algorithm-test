#include <algorithm>
#include <bits/stdc++.h>
#include <cstddef>
#include <strings.h>
#include <unordered_set>
#include <vector>
using namespace std;
class Solution {
public:
  int findNumberOfLIS(vector<int> &nums) {
    vector<int> dp(nums.size()), count(nums.size());
    dp[0] = 1;
    count[0] = 1;

    for (size_t index = 1; index < nums.size(); index++) {
      int max = 0, cnt = 1;

      for (size_t dp_index = 0; dp_index < index; dp_index++) {
        if (nums[index] > nums[dp_index]) {
          // the max length change
          if (dp[dp_index] > max) {
            max = dp[dp_index];
            cnt = count[dp_index];
            continue;
          }
          // the same max length
          if (dp[dp_index] == max) {
            cnt += count[dp_index];
            continue;
          }
        }
      }

      dp[index] = max + 1;
      count[index] = cnt;
    }

    int max = 0, res = 0;
    for (size_t index = 0; index < dp.size(); index++) {
      if (max < dp[index]) {
        max = dp[index];
        res = count[index];
        continue;
      }
      if (max == dp[index]) {
        res += count[index];
      }
    }
    return res;
  }
};

int main() {
  vector<int> s1{1, 3, 2};
  Solution s;
  cout << s.findNumberOfLIS(s1);
}
