// this solution's time complexity is O(n^2)
#include <bits/stdc++.h>
#include <limits>
using namespace std;

class solution {
public:
  int lengthOfLIS(vector<int> &nums) {
    vector<int> dp(nums.size(), 0);
    dp[0] = 1;
    int res = 1;

    for (size_t index_1 = 1; index_1 < nums.size(); index_1++) {
      int max_len = 0;
      for (size_t index_2 = 0; index_2 < index_1; index_2++) {
        if ((nums[index_1] > nums[index_2]) && dp[index_2] > max_len)
          max_len = dp[index_2];
      }
      dp[index_1] = max_len + 1;
      if (dp[index_1] > res)
        res = dp[index_1];
    }
    return res;
  }
};

int main() {
  vector<int> s1{1, 3, 6, 7, 9, 4, 10, 5, 6};
  solution s;
  cout << s.lengthOfLIS(s1);
}
