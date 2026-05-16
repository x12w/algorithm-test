#include <bits/stdc++.h>
using namespace std;

class solution
{
public:
    int minmumDeleteSum(string s1, string s2)
    {
        int len1 = s1.length(), len2 = s2.length();
        vector<vector<int>> dp(len1 + 1, vector<int>(len2 + 1, 0));

        for (int i = 1; i <= len1; i++)
            dp[i][0] = dp[i - 1][0] + s1[i - 1];
        for (int i = 1; i <= len2; i++)
            dp[0][i] = dp[0][i - 1] + s2[i - 1];

        for (int i = 1; i <= len1; i++)
        {
            for (int j = 1; j <= len2; j++)
            {
                if (s1[i - 1] == s2[j - 1])
                {
                    dp[i][j] = dp[i - 1][j - 1];
                    continue;
                }
                else
                {
                    if (dp[i - 1][j] + s1[i - 1] < dp[i][j - 1] + s2[j - 1])
                    {
                        dp[i][j] = dp[i - 1][j] + s1[i - 1];
                        continue;
                    }
                    else
                    {
                        dp[i][j] = dp[i][j - 1] + s2[j - 1];
                        continue;
                    }
                }
            }
        }

        return dp[len1][len2];
    };
};

int main()
{
    string s1{"horse"}, s2{"ros"};
    solution s;
    cout << s.minmumDeleteSum(s1, s2);
}