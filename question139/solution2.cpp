#include<bits/stdc++.h>
using namespace std;

class solution{
    public:
    bool wordBreak(string s,vector<string> &wordDict){
        vector<int> dp(s.size()+1,0);
        dp[0]=1;

        for(int i=1;i<dp.size();i++){
            for(const auto &str:wordDict){
                //检查字符串长度和当前索引，若长度大于索引，则直接跳过本轮循环
                if(str.size()>i){
                    continue;
                }

                if(s.find(str,i-str.size())==i-str.size() && dp[i-str.size()]==1){
                    dp[i]=1;
                    break;
                }
            }
        }

        /*
        for (auto val:dp){
            cout << val << " ";
        }
        cout <<endl;
        */

        if(dp[dp.size()-1]==1){
            return true;
        }
        else{
            return false;
        }
    }
};


int main(){
    string s{"leetcode"};
    vector<string> wordList{"leet","code"};
    solution s1;
    cout << s1.wordBreak(s,wordList) << endl;
    return 0;
}