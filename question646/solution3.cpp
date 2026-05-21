#include <bits/stdc++.h>
#include <cstddef>
#include <vector>
using namespace std;

class Solution {
public:
  int findLongestChain(vector<vector<int>> &pairs) {
    sort(pairs.begin(), pairs.end(),
         [](vector<int> &v1, vector<int> &v2) { return v1[1] < v2[1]; });

    vector<int> d{};
    d.push_back(pairs[0][1]);

    for (size_t index = 0; index < pairs.size(); index++) {
      if (pairs[index][0] > d.back()) {
        d.push_back(pairs[index][1]);
      }
    }

    return d.size();
  }
};

int main() {
  Solution s;
  vector<vector<int>> pairs{{1, 2}, {7, 8}, {4, 5}};
  cout << s.findLongestChain(pairs);
}
