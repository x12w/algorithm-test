#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int minInsertions(string s) {
    if (s.size() < 2) {
      return 0;
    }
    vector<vector<int>> dp(s.size(), vector<int>(s.size(), 0));

    for (size_t index = 0; index < dp.size(); index++) {
      dp[index][index] = 1;
      if (index < s.size() - 1) {
        if (s[index] == s[index + 1])
          dp[index][index + 1] = 2;
        else
          dp[index][index + 1] = 1;
      }
    }

    for (size_t len = 3; len <= s.size(); len++) {
      for (size_t index = 0; index < s.size() - len + 1; index++) {
        if (s[index] == s[index + len - 1]) {
          dp[index][index + len - 1] = dp[index + 1][index + len - 2] + 2;
        } else {
          dp[index][index + len - 1] =
              max(dp[index + 1][index + len - 1], dp[index][index + len - 2]);
        }
      }
    }
    return s.size() - dp[0].back();
  }
};

int main() {
  Solution s;
  string s1{"zzazz"};
  cout << s.minInsertions(s1);
}
