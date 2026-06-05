#include <bits/stdc++.h>
#include <vector>
using namespace std;

class Solution {
public:
  int minInsertions(string s) {
    int dp[501][501] = {};

    for (int len = 2; len <= s.size(); len++) {
      for (int i = 0; i + len - 1 < s.size(); i++) {
        int j = i + len - 1;
        if (s[i] == s[j]) {
          dp[i][j] = dp[i + 1][j - 1];
        } else {
          dp[i][j] = min(dp[i + 1][j], dp[i][j - 1]) + 1;
        }
      }
    }

    return dp[0][s.size() - 1];
  }
};

int main() {
  Solution s;
  string s1{"mbadm"};
  cout << s.minInsertions(s1);
}
