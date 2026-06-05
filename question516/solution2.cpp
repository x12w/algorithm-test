#include <bits/stdc++.h>
using namespace std;

class solution {
public:
  int longestPalindromeSubseq(string s) {
    int dp[1001][1001] = {};

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

    return s.size() - dp[0][s.size() - 1];
  }
};

int main() {
  string s{"abcabcabcabc"};
  solution sol;
  cout << sol.longestPalindromeSubseq(s) << endl;
  return 0;
}
