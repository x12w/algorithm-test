#include <algorithm>
#include <bits/stdc++.h>
#include <cstddef>
#include <vector>
using namespace std;

class Solution {
public:
  int maxEnvelopes(vector<vector<int>> &envelopes) {
    sort(envelopes.begin(), envelopes.end(),
         [](const vector<int> &one, const vector<int> &another) {
           return one[0] < another[0] ||
                  one[0] == another[0] && one[1] > another[1];
         });

    vector<int> len{envelopes[0][1]};

    for (size_t index = 1; index < envelopes.size(); index++) {
      int num = envelopes[index][1];
      if (num > len.back()) {
        len.push_back(num);
        continue;
      } else {
        auto it = lower_bound(len.begin(), len.end(), num);
        *it = num;
      }
    }

    return len.size();
  }
};

int main() {
  Solution s;
  vector<vector<int>> v{{2, 100}, {3, 200}, {4, 300}, {5, 500}, {5, 400},
                        {5, 250}, {6, 370}, {6, 360}, {7, 380}};
  cout << s.maxEnvelopes(v);
}
