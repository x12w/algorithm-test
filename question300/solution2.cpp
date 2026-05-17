#include <bits/stdc++.h>
#include <vector>
using namespace std;
// this solution's time complexity is O(nlogn)
class Solution {
public:
  int lengthOfLIS(vector<int> &nums) {
    vector<int> d{};
    d.push_back(nums[0]);

    for (size_t index = 1; index < nums.size(); index++) {
      size_t left = 0, right = d.size();
      while (right > left) {
        size_t div = (left + right) / 2;

        if (d[div] < nums[index]) {
          left = div + 1;
          continue;
        }

        if (d[div] >= nums[index]) {
          right = div;
          continue;
        }
      }
      if (right == d.size()) {
        d.push_back(nums[index]);
        continue;
      }
      d[left] = nums[index];
    }

    return d.size();
  }
};

int main() {
  vector<int> s1{1, 3, 6, 7, 9, 4, 10, 5, 6};
  Solution s;
  cout << s.lengthOfLIS(s1);
}
