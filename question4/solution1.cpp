#include <vector>
//
// Created by x12w on 2025/11/22.
//
#include<bits/stdc++.h>
using namespace std;

class solution {
    private:
    double  find_k(vector<int> &nums1, vector<int> &nums2,int begin1,int begin2, int k) {
        //将k转换为索引值
        k-=1;

        //计算此次迭代索引
        int index_1=begin1+k/2-1,index_2=begin2+k/2-1;

        //处理边界情况:数组长度为零
        if (nums1.size()==0) {
            //cout <<nums2[k] << endl;
            return nums2[k];
        }
        if (nums2.size()==0) {
            //cout <<nums1[k] << endl;
            return nums1[k];
        }

        //边界情况:数组剩余长度为零
        if (begin1==nums1.size()) {
            //cout << nums2[begin2+k+1] << endl;
            return nums2[begin2+k];
        }
        if (begin2==nums2.size()) {
            //cout <<nums1[begin1+k+1] << endl;
            return nums1[begin1+k];
        }

        //处理边界情况:k=0/1
        if (k==0) {
            //cout << min(nums1[begin1],nums2[begin2]) << endl;
            return min(nums1[begin1], nums2[begin2]);
        }
        if (k==1) {
            if (begin1 == nums1.size()-1) {
                if (begin2 == nums2.size()-1) {
                    //cout << max(nums1[begin1],nums2[begin2]) << endl;
                    return max(nums1[begin1], nums2[begin2]);
                }
                if (nums1[begin1] < nums2[begin2]) {
                    //cout << nums2[begin2] << endl;
                    return nums2[begin2];
                }
                else {
                    //cout << min(nums1[begin1],nums2[begin2+1]) << endl;
                    return min(nums1[begin1], nums2[begin2+1]);
                }
            }
            if (begin2 == nums2.size()-1) {
                if (nums2[begin2] < nums1[begin1]) {
                    //cout << nums1[begin1] << endl;
                    return nums1[begin1];
                }
                else {
                    //cout << min(nums2[begin2],nums1[begin1+1]) << endl;
                    return min(nums2[begin2], nums1[begin1+1]);
                }
            }
            //cout << (nums1[begin1]>nums2[begin2] ? min(nums1[begin1],nums2[begin2+1]) : min(nums2[begin2],nums1[begin1+1]));
            return (nums1[begin1]>nums2[begin2] ? min(nums1[begin1],nums2[begin2+1]) : min(nums2[begin2],nums1[begin1+1]));
        }


        //特殊情况，数组越界
        if (index_1>=nums1.size()) {
            //比较越界数组的尾元素与另一数组的对应元素
            if (nums1[nums1.size()-1]<nums2[begin2+k-nums1.size()+begin1]) {
                return find_k(nums1,nums2,nums1.size(),begin2,k+1-nums1.size()+begin1);
            }
            else {
                return find_k(nums1,nums2,begin1,begin2+k+1-nums1.size()+begin1,nums1.size()-begin1);
            }
        }
        if (index_2>=nums2.size()) {
            if (nums2[nums2.size()-1]<nums1[begin1+k-nums2.size()+begin2]) {
                return find_k(nums1,nums2,begin1,nums2.size(),k+1-nums2.size()+begin2);
            }
            else {
                return find_k(nums1,nums2,begin1+k+1-nums2.size(),begin2,nums2.size()-begin2);
            }
        }

        //一般情况
        if (nums1[index_1]<nums2[index_2]) {
            return find_k(nums1,nums2,index_1+1,begin2,k+1-k/2);
        }
        else {
            return find_k(nums1,nums2,begin1,index_2+1,k+1-k/2);
        }
    }
    public:
    double findMedianSortedArrays(vector<int> &nums1,vector<int> nums2) {
        double result;
        if ((nums1.size()+nums2.size())%2==0) {
            result = find_k(nums1,nums2,0,0,(nums1.size()+nums2.size())/2);
            result += find_k(nums1,nums2,0,0,(nums1.size()+nums2.size())/2+1);
            result/=2;
        }
        else {
            result = find_k(nums1,nums2,0,0,(nums1.size()+nums2.size())/2+1);
        }
        return result;
    }
};


int main() {
    vector<int> nums1{1,2,3,4,5,7,8},nums2{6};
    solution s;
    cout << s.findMedianSortedArrays(nums1,nums2) << endl;

}