#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int longestArithSeqLength(vector<int> &nums) {
    auto [min_ele, max_ele] = minmax_element(nums.begin(), nums.end());
    int diff = *max_ele - *min_ele;
    int res = 0;

    for (int difference = -diff; difference <= diff; difference++) {
      int offset = -*min_ele,
          dif_abs = difference < 0 ? -difference : difference;
      vector<int> dp(*max_ele - *min_ele + dif_abs + 1, 0);

      for (auto ele : nums) {
        int index = ele + offset;
        if (difference > 0)
          index += difference;
        dp[index] = dp[index - difference] + 1;
        res = max(res, dp[index]);
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
