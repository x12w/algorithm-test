#include <bits/stdc++.h>
using namespace std;

class solution {
public:
  int longestCommonSubsequence(string text1, string text2) {
    auto smaller = (text1.size() < text2.size() ? &text1 : &text2),
         bigger = (text1.size() < text2.size() ? &text2 : &text1);
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
  string s1{"a"}, s2{"a"};
  solution s;
  cout << s.longestCommonSubsequence(s1, s2) << endl;
  return 0;
}
