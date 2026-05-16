//
// Created by x12w on 2025/12/3.
//
#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
    string longestPalindos(string s) {
       if (s.length() < 2) {
           return s;
       }
        int max_len=0;
        pair<int,int> max_pos;

        vector<vector<int>> dp(s.size(), vector<int>(s.size(), 1));

        for (int i=0;i<=s.size()*2-2;i++) {
            for (int j=i/2;j>=0 && i-j<s.size();j--) {
                if (i%2==1 && j+1==i-j) {
                    if (s[j]==s[i-j]) {
                        dp[j][i-j]=2;

                        if (dp[j][i-j]>max_len) {
                            max_len = dp[j][i-j];
                            max_pos = {j,i-j};
                        }

                        continue;
                    }
                }

                if (i%2==0 && j==i-j) {
                    dp[j][i-j]=1;

                    if (dp[j][i-j]>max_len) {
                        max_len = dp[j][i-j];
                        max_pos = {j,i-j};
                    }

                    continue;

                }


                if (s[j]==s[i-j]) {
                    dp[j][i-j]=dp[j+1][i-j-1]+2;

                    if (dp[j][i-j]>max_len) {
                        max_len = dp[j][i-j];
                        max_pos = {j,i-j};
                    }
                }
                else {
                    break;
                }
            }
        }
        for (auto row:dp) {
            for (auto col:row) {
                cout<<col<<"\t";
            }
            cout<<endl;
        }
        return s.substr(max_pos.first, max_pos.second-max_pos.first+1);
    }
};

int main() {
    string s("kuhrjauwhjgiuohuhriughrkhgilrhgihrilsughsriusyhgirkuhsikrghishrgihrikhslriuyhgihsiurhg");
    Solution so;
    cout << so.longestPalindos(s) << endl;
}