#include <bits/stdc++.h>
#include <cstddef>
using namespace std;

class Solution {
public:
  int longestArithSeqLength(vector<int> &nums) {
    vector<vector<int>> sub(nums.size(), vector<int>());
    vector<map<int, int>> sub_sets(nums.size());

    for (size_t index1 = 0; index1 < nums.size(); index1++) {
      for (size_t index2 = 0; index2 < index1; index2++) {
        sub[index1].push_back(nums[index1] - nums[index2]);
        if (sub_sets[index2].count(nums[index1] - nums[index2]) == 0)
          sub_sets[index2].insert({nums[index1] - nums[index2], index1});
      }
    }

    int res = 0, res_dif, res_begin;
    for (size_t index = 0; index < sub_sets.size(); index++) {
      while (!sub_sets[index].empty()) {
        int sub_temp = (*sub_sets[index].begin()).first, index_temp = index,
            cnt = 1;
        while (sub_sets[index_temp].count(sub_temp) > 0) {
          cnt++;
          index_temp = sub_sets[index_temp][sub_temp];
        }
        if (cnt > res) {
          res_dif = sub_temp;
          res_begin = nums[index];
        }
        res = max(res, cnt);
      }
    }

    cout << "the diff is " << res_dif << endl;
    cout << "the nums are " << endl;

    for (int i = 0; i < res; i++) {
      cout << res_begin << " ";
      res_begin += res_dif;
    }
    cout << endl;

    return res;
  }
};

int main() {
  Solution s;
  vector<int> d{22, 8,  57, 41, 36, 46, 42, 28, 42, 14, 9,  43, 27, 51,
                0,  0,  38, 50, 31, 60, 29, 31, 20, 23, 37, 53, 27, 1,
                47, 42, 28, 31, 10, 35, 39, 12, 15, 6,  35, 31, 45, 21,
                30, 19, 5,  5,  4,  18, 38, 51, 10, 7,  20, 38, 28, 53,
                15, 55, 60, 56, 43, 48, 34, 53, 54, 55, 14, 9,  56, 52};
  cout << s.longestArithSeqLength(d);
}
