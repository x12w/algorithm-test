#include <bits/stdc++.h>
#include <cinttypes>
#include <cstddef>
#include <functional>
#include <pthread.h>
#include <vector>
using namespace std;

class Solution {
public:
  size_t binary_search(int n, function<bool(int)> f) {
    size_t left = 0, right = n;

    while (right > left) {
      size_t middle = left + (right - left) / 2;

      if (f(middle)) {
        right = middle;
      } else {
        left = middle + 1;
      }
    }

    return left;
  }

  int findNumberOfLIS(vector<int> &nums) {

    vector<vector<int>> dp{}, cnt{};

    for (int num : nums) {
      size_t i =
          binary_search(dp.size(), [&](int i) { return num <= dp[i].back(); });
      int c = 1;
      if (i > 0) {
        int k = binary_search(dp[i - 1].size(),
                              [&](int n) { return dp[i - 1][n] < num; });
        c = cnt[i - 1].back() - cnt[i - 1][k];
      }
      if (i == dp.size()) {
        dp.push_back(vector<int>{num});
        cnt.push_back(vector<int>{0, c});
      } else {
        dp[i].push_back(num);
        cnt[i].push_back(cnt[i].back() + c);
      }
    }
    return cnt.back().back();
  }
};

int main() {
  Solution s;
  vector<int> v{1, 3, 2};

  s.findNumberOfLIS(v);
}
