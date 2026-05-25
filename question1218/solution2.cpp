#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int longestSubsequence(vector<int> &arr, int difference) {
    int min_ele = arr[0], max_ele = arr[0];

    for (auto ele : arr) {
      min_ele = min(min_ele, ele);
      max_ele = max(max_ele, ele);
    }

    int offset = -min_ele, dif_abs = difference < 0 ? -difference : difference;
    vector<int> dp(max_ele - min_ele + dif_abs + 1, 0);

    int res = 0;
    for (auto ele : arr) {
      int index = ele + offset;
      if (difference > 0)
        index += difference;
      dp[index] = dp[index - difference] + 1;
      res = max(res, dp[index]);
    }

    return res;
  }
};

int main() {
  Solution s;
  vector<int> v{};
  cout << s.longestSubsequence(v, 1);
}
