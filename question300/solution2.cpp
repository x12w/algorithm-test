#include <bits/stdc++.h>
#include <vector>
using namespace std;
// this colution's time complexity is O(nlogn)
class Solution {
public:
  int lengthOfLIS(vector<int> &nums) {
    vector<int> d{};
    d.push_back(nums[0]);
    int len = 1;

    for (size_t index = 1; index < nums.size(); index++) {
      if (nums[index] > d[len - 1]) {
        d.push_back(nums[index]);
        len++;
        continue;
      }

      size_t left = 0, right = d.size() - 1;
      while (right > left) {
        // in each turn, take the pair d[(left + right) / 2] and d[(left +
        // right) / 2 + 1], because the two elements are always in the valid
        // field
        size_t div = (left + right) / 2;
        if ((d[div + 1] > nums[index]) && (d[div] < nums[index])) {
          d[div + 1] = nums[index];
          break;
        }

        if (d[div] >= nums[index]) {
          right = div;
          continue;
        }

        if (d[div + 1] <= nums[index]) {
          left = div + 1;
          continue;
        }
      }
      if (right <= left && left == 0) {
        d[0] = nums[index];
      }
    }

    return len;
  }
};

int main() {
  vector<int> s1{1, 3, 6, 7, 9, 4, 10, 5, 6};
  Solution s;
  cout << s.lengthOfLIS(s1);
}
