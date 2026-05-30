#include <bits/stdc++.h>
#include <csignal>
#include <cstddef>
#include <functional>
using namespace std;

class Solution {
public:
  int binary_search(int n, function<bool(int)> f) {
    int left = 0, right = n;
    while (left < right) {
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
  vector<int> longestObstacleCourseAtEachPosition(vector<int> &obstacles) {
    if (obstacles.size() == 0) {
      return {};
    }
    vector<int> res(obstacles.size()), d{};
    res[0] = 1;
    d.push_back(obstacles[0]);

    for (size_t index = 1; index < obstacles.size(); index++) {
      int num = obstacles[index],
          i_e = binary_search(d.size(), [&](int n) { return d[n] <= num; });
      res[index] = i_e + 1;
      if (i_e == d.size()) {
        d.push_back(num);
        continue;
      } else {
        d[i_e] = num;
      }
    }

    return res;
  }
};

int main() {
  Solution s;
  vector<int> v{3, 1, 5, 6, 4, 2};
  auto res = s.longestObstacleCourseAtEachPosition(v);
  for (const auto &ele : res) {
    cout << ele << " ";
  }
  cout << endl;
}
