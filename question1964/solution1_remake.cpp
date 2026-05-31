#include <algorithm>
#include <bits/stdc++.h>
#include <cstddef>
using namespace std;

class Solution {
public:
  vector<int> longestObstacleCourseAtEachPosition(vector<int> &obstacles) {
    vector<int> d{}, res(obstacles.size());
    res[0] = 1;
    d.push_back(obstacles[0]);

    for (size_t index = 1; index < obstacles.size(); index++) {
      int num = obstacles[index];
      int loc = upper_bound(d.begin(), d.end(), num) - d.begin();

      res[index] = loc + 1;
      if (loc == d.size()) {
        d.push_back(num);
        continue;
      } else {
        d[loc] = num;
      }
    }
    return res;
  }
};

int main() {}
