#include <string>
#include <vector>
//
// Created by x12w on 2025/11/30.
//
#include<bits/stdc++.h>
using namespace std;

class solution {
    private:
    int get_length(string &s,int index) {
        int double_len=0,single_len=1;
        for (int left=index,right=index+1;left>=0 && right<s.size();right++,left--) {
            if(s[left]==s[right]) {
                double_len+=2;
            }
            else {
                break;
            }
        }
        for (int left=index-1,right=index+1;left>=0 && right>=0;left--,right++) {
            if(s[left]==s[right]) {
                single_len+=2;
            }
            else {
                break;
            }
        }
        return max({double_len,single_len});
    }
    string print_palindrome(string &s,int length,int index) {
        if (length%2==0) {
            string result;
            for (int index_1=index-(length/2-1);index_1<=index+length/2;index_1++) {
                result.push_back(s[index_1]);
            }
            return result;
        }
        else {
            string result;
            for (int index_1=index-length/2;index_1<=index+length/2;index_1++) {
                result.push_back(s[index_1]);
            }
            cout << endl;
            return result;
        }
    }

    public:
    string longestPalindrome(string s) {
        int max_len=0,max_index;
        for (int index_1=0;index_1<s.size();index_1++) {
            int temp=get_length(s,index_1);
            if(temp>max_len) {
                max_len=temp;
                max_index=index_1;
            }
        }
        return print_palindrome(s,max_len,max_index);
    }
};