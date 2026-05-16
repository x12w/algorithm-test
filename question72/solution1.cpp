#include <bits/stdc++.h>
using namespace std;

class solution
{
private:
    bool isValid(int i, int j)
    {
        if (i < 0 || j < 0)
            return false;
        else
            return true;
    }

public:
    int minDistance(string word1, string word2)
    {
        int len1 = word1.length(), len2 = word2.length();
        vector<vector<int>> dp(len1 + 1, vector<int>(len2 + 1, 0));

        for (int i = 0; i <= len1; i++)
        {
            dp[i][0] = i;
        }
        for (int i = 0; i <= len2; i++)
        {
            dp[0][i] = i;
        }

        for (int i = 1; i <= len1; i++)
        {
            for (int j = 1; j <= len2; j++)
            {
                if (word1[i - 1] == word2[j - 1])
                {
                    dp[i][j] = dp[i - 1][j - 1];
                }
                else
                {
                    dp[i][j] = 1 + min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]});
                }
            }
        }
        for (const auto &row : dp)
        {
            for (const auto &col : row)
            {
                cout << col << " ";
            }
            cout << endl;
        }
        return dp[len1][len2];
    };
};

int main()
{
    string s1{"horse"}, s2{"ros"};
    solution s;
    cout << s.minDistance(s1, s2);
}