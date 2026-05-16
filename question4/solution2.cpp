//
// Created by x12w on 2025/11/29.
//
#include<bits/stdc++.h>
using namespace std;


class Solution {
    public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size()>nums2.size()) {
            return findMedianSortedArrays(nums2, nums1);
        }
        int len1 = nums1.size(), len2 = nums2.size();
        int left=0, right=len1;
        int left_max,right_min;

        while (left <= right) {
            int div1 = left + (right - left) / 2;
            int div2 = (len1+len2+1)/2 -div1;

            int num_lm1 = (div1 ==0) ? INT_MIN : nums1[div1-1];
            int num_lm2 = (div2 == 0) ? INT_MIN : nums2[div2-1];
            int num_rm1 = (div1 == len1) ? INT_MAX : nums1[div1];
            int num_rm2 = (div2 == len2) ? INT_MAX : nums2[div2];

            if (num_lm1 <= num_rm2) {
                left = div1+1;
                left_max = max(num_lm1,num_lm2);
                right_min = min(num_rm1,num_rm2);
            }
            else {
                right = div1-1;
            }

        }
        return (len1+len2)%2 == 0 ? (left_max + right_min)/(double)2 : left_max;
    }
};


int main() {
    vector<int> nums1{}, nums2{3};
    Solution s;
    cout << s.findMedianSortedArrays(nums1, nums2) << endl;
}