//
// Created by x12w on 2025/12/8.
//
#include<bits/stdc++.h>
using namespace std;

class solution {
    public:
    int expand_len(const string &s,int left_index,int right_index) {
        while (left_index>=0 && right_index<s.size() && s[left_index]==s[right_index]) {
            left_index--;right_index++;
        }
        return (right_index-left_index-2)/2;
    }
    string longestPalindrome(string s) {
        string temp="@";
        for (auto c : s) {
            temp+=c;
            temp+='@';
        }
        s=std::move(temp);

        int right_bound=-1,current_middle,current_len;
        int max_len=0,max_pos=0;
        vector<int> length(s.length(),0);

        for (int i=0;i<s.length();i++) {
            //遍历节点在右界以内
            if (i<right_bound) {
                //获取对称节点臂长
                int n=length[current_middle*2-i];
                //确定当前节点的最短臂长
                int new_len=min(n,right_bound-i);
                //若当前节点的右界和已知右界相同，需对该节点进行中心扩展
                if (i+new_len==right_bound) {
                    int temp_len=expand_len(s,i-new_len,right_bound);
                    //若扩展后节点右界超过当前右界，进行更新
                    if (i+temp_len>right_bound) {
                        current_len=temp_len;
                        current_middle=i;
                        right_bound=i+temp_len;
                        length[i]=temp_len;
                    }
                    //扩展后不超过右界，直接存储
                    else {
                        length[i]=new_len;
                    }
                }
                //当前节点的右界在已知右界内，直接存储
                else {
                    length[i]=new_len;
                }
            }
            //遍历节点在右界及右界之外
            else {
                int temp_len=expand_len(s,i,i);
                current_middle=i;
                current_len=temp_len;
                right_bound=i+temp_len;
                length[i]=temp_len;
            }
            if (length[i]>max_len) {
                max_len=length[i];
                max_pos=i;
            }
        }
        string result;
        for (int i=max_pos-max_len;i<=max_pos+max_len;i++) {
            if (s[i]!='@') {
                result += s[i];
            }
        }
        return result;
    }
};

int main() {
    solution s;
    string s1{"abba"};
    cout << s.longestPalindrome(s1) << endl;
}