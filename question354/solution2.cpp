#include <algorithm>
#include <bits/stdc++.h>
#include <cstddef>
#include <functional>
#include <numeric>
#include <random>
#include <strings.h>
#include <system_error>
#include <vector>
using namespace std;

class Solution {
  inline int binary_search(int n, function<bool(int)> f) {
    int left = 0, right = n;

    while (right > left) {
      int middle = left + (right - left) / 2;

      if (f(middle)) {
        left = middle + 1;
        continue;
      } else {
        right = middle;
      }
    }
    return left;
  }
  inline int findLIS(vector<vector<int>> &arr) {
    if (arr.size() < 2) {
      return arr.size();
    }
    vector<vector<int>> length{};
    length.push_back(arr[0]);

    for (const auto &ele : arr) {
      int i = binary_search(length.size(),
                            [&](int n) { return length[n][1] < ele[1]; });
      if (i == length.size()) {
        if (ele[0] > length.back()[0])
          length.push_back(ele);
      } else {
        length[i] = ele;
      }
    }

    return length.size();
  }

public:
  int maxEnvelopes(vector<vector<int>> &envelopes) {
    if (envelopes.size() < 2) {
      return envelopes.size();
    }

    sort(envelopes.begin(), envelopes.end(),
         [](vector<int> one, vector<int> another) {
           return one[1] > another[1];
         });

    stable_sort(envelopes.begin(), envelopes.end(),
                [](vector<int> one, vector<int> another) {
                  return one[0] < another[0];
                });

    return findLIS(envelopes);
  }
};

int main() {
  Solution s;
  vector<vector<int>> v{{2, 100}, {3, 200}, {4, 300}, {5, 500}, {5, 400},
                        {5, 250}, {6, 370}, {6, 360}, {7, 380}};
  cout << s.maxEnvelopes(v);
}
