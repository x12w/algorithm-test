#include <bits/stdc++.h>
#include <cstddef>
using namespace std;

class Solution {
public:
  int maxEnvelopes(vector<vector<int>> &envelopes) {
    if (envelopes.size() < 2) {
      return envelopes.size();
    }

    sort(envelopes.begin(), envelopes.end(),
         [](vector<int> one, vector<int> another) {
           return one[0] < another[0];
         });
    vector<int> dp(envelopes.size(), 0);
    dp[0] = 1;
    int res = 0;
    for (size_t index1 = 1; index1 < envelopes.size(); index1++) {
      int max_len = 0;
      for (size_t index2 = 0; index2 < index1; index2++) {
        if (envelopes[index1][0] > envelopes[index2][0] &&
            envelopes[index1][1] > envelopes[index2][1]) {
          max_len = max(max_len, dp[index2]);
        }
      }
      dp[index1] = max_len + 1;
      res = max(res, dp[index1]);
    }

    return res;
  }
};

int main() {
  Solution s;
  vector<vector<int>> v{{1, 1}, {1, 1}, {1, 1}};
  cout << s.maxEnvelopes(v);
}
