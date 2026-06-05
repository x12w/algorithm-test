#include <bits/stdc++.h>
#include <vector>
using namespace std;

class Solution {
public:
  int minInsertions(string s) {
    if (s.size() < 2) {
      return 0;
    }

    vector<vector<int>> dp(s.size() + 1, vector<int>(s.size() + 1, 0));
    for (int i = 0; i <= s.size(); i++) {
      dp[0][i] = s.size() - i;
      dp[i].back() = i;
    }

    for (const auto &row : dp) {
      for (const auto &ele : row) {
        cout << ele << " ";
      }
      cout << endl;
    }
    cout << endl;

    for (int index1 = 1; index1 <= s.size(); index1++) {
      int offset = index1 - s.size() + 1;
      for (int index2 = s.size() - 1; index2 + offset >= 1; index2--) {
        if (s[index2 + offset - 1] == s[index2])
          dp[index2 + offset][index2] = dp[index2 + offset - 1][index2 + 1];
        else
          dp[index2 + offset][index2] = min(dp[index2 + offset - 1][index2],
                                            dp[index2 + offset][index2 + 1]) +
                                        1;
      }
    }

    int res = dp[1][0];
    for (int i = 1; i <= s.size(); i++) {
      res = min(res, dp[i][i - 1]);
      res = min(res, dp[i][i]);
    }

    for (const auto &row : dp) {
      for (const auto &ele : row) {
        cout << ele << " ";
      }
      cout << endl;
    }
    cout << endl;
    return res;
  }
};

int main() {
  Solution s;
  string s1{"mbadm"};
  cout << s.minInsertions(s1);
}
