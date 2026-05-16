#include <bits/stdc++.h>
using namespace std;

class solution
{
public:
    int numDistinct(string s, string t)
    {
        int len1 = s.length(), len2 = t.length();
        vector<vector<unsigned long long int>> dp(len1 + 1, vector<unsigned long long int>(len2 + 1, 0));

        for (int i = 0; i <= len1; i++)
            dp[i][0] = 1;

        for (int i = 1; i <= len1; i++)
        {
            for (int j = 1; j <= len2; j++)
            {
                if (s[i - 1] == t[j - 1])
                {
                    dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1];
                    continue;
                }
                else
                {
                    dp[i][j] = dp[i - 1][j];
                    continue;
                }
            }
        }

        return dp[len1][len2];
    };
};

int main()
{
    string s{"aaaaaaa"}, t{"aaa"};
    solution sl;
    cout << sl.numDistinct(s, t);
}