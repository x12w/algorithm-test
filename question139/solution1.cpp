#include<bits/stdc++.h>
using namespace std;

class solution{
    public:
    bool wordBreak(string s, vector<string> &wordDict){
        //存储可以用字符串序列拼接的字符串的末字符后索引
        vector<int> valid_index(1,0);

        //对给定字符串进行遍历
        for (int i=0;i<s.size();i++){
            //对每个字符检查是否为可组成字符串的末尾字符
            for(int j=0;j<valid_index.size();j++){
                for(const auto &str:wordDict){
                    if(s.find(str,valid_index[j])==valid_index[j] && valid_index[j]+str.size()==i+1){
                        valid_index.push_back(i+1);
                        break;
                    }
                }
            }
        }

        if(valid_index[valid_index.size()-1]==s.size()){
            return true;
        }
        else{
            return false;
        }
    }
};


int main(){
    string s{"catsandog"};
    vector<string> wordList{"cats","dog","sand","and","cat"};
    solution s1;
    cout << s1.wordBreak(s,wordList) << endl;
    return 0;
}