#include<bits/stdc++.h>
using namespace std;

class solution{
    public:
    int longestCommonSubsequence(string text1, string text2){
        vector<vector<int>> dp(text1.size(),vector<int>(text2.size(),0));
        int maxLen = 0;
        for (int i=0;i<text1.size();i++){
            for (int j=0;j<text2.size();j++){
                if (text1[i] == text2[j]){
                    if (i == 0 || j==0){
                        dp[i][j] = 1;
                        maxLen = max(maxLen,dp[i][j]);
                        continue;
                    }
                    dp[i][j] = dp[i-1][j-1] + 1;
                }
                else {
                    if (i == 0 || j==0){
                        if (i == 0 && j == 0){
                            dp[i][j] = 0;
                            continue;
                        }
                        if (i == 0)
                            dp[i][j] = dp[i][j-1];
                        if(j == 0)
                            dp[i][j] = dp[i-1][j];
                        maxLen = max(maxLen,dp[i][j]);
                        continue;
                    }
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
                maxLen = max(maxLen,dp[i][j]);
            }
        }
        for (auto row:dp){
            for (auto col:row){
                cout << col << " ";
            }
            cout << endl;
        }
        return maxLen;
    }
};


int main(){
    string s1{"a"},s2{"a"};
    solution s;
    cout << s.longestCommonSubsequence(s1, s2) << endl;
    return 0;
}