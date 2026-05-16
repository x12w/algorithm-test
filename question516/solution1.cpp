#include<bits/stdc++.h>
using namespace std;

class solution{
    public:
    int longestPalindromeSubseq(string s){
        vector<vector<int>> dp(s.size(),vector<int>(s.size(),0));
        int maxLen=0;
        for(int len=1;len<=s.size();len++){
            for(int i=0;i+len-1<s.size();i++){
                int right=i+len-1;
                
                //新串的首尾字符相等
                if (s[i]==s[right]){
                    //边界情况
                    if (len == 1){
                        dp[i][right] = 1;
                    } else if (len == 2){
                        dp[i][right] = 2;
                    }
                    //普通情况,串长大于2
                    else {
                        dp[i][right] = dp[i+1][right-1] + 2;
                    } 
                }
                //新串的首尾字符不相等
                else {
                    //边界情况
                    if (len == 2){
                        dp[i][right] = 1;
                    } 
                    //普通情况,串长大于2
                    else {
                        dp[i][right] = max(dp[i+1][right], dp[i][right-1]);
                    }
                }
                maxLen = max(maxLen, dp[i][right]);
            }
        }
        for (auto row : dp){
            for (auto val : row){
                cout << val << " ";
            }
            cout << endl;
        }
        return maxLen;
    }
};



int main(){
    string s{"abcabcabcabc"};
    solution sol;
    cout<<sol.longestPalindromeSubseq(s)<<endl;
    return 0;
}