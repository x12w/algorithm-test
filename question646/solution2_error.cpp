#include <algorithm>
#include <bits/stdc++.h>
#include <cstddef>
#include <functional>
#include <vector>
using namespace std;

class Solution {
public:
  size_t binary_search(size_t n, function<bool(size_t)> f) {
    size_t left = 0, right = n;
    while (right > left) {
      size_t middle = left + (right - left) / 2;
      if (f(middle)) {
        left = middle + 1;
      } else {
        right = middle;
      }
    }
    return left;
  }
  int findLongestChain(vector<vector<int>> &pairs) {
    sort(pairs.begin(), pairs.end(),
         [](vector<int> &v1, vector<int> &v2) -> bool {
           if (v1[1] < v2[1]) {
             return true;
           } else {
             if (v1[1] == v2[1] && v1[0] > v2[0]) {
               return true;
             }
             return false;
           }
         });

    vector<int> d{};

    for (const auto &p : pairs) {
      if (d.empty()) {
        d.push_back(p[1]);
        continue;
      }

      size_t i = binary_search(d.size(), [&](size_t k) { return d[k] < p[0]; });

      if (i == d.size()) {
        d.push_back(p[1]);
      } else {
        d[i] = p[1];
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
