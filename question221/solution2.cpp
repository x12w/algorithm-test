#include <format>
#include <vector>
#include <vector>
//
// Created by x12w on 2025/11/27.
//
class solution {
    public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int row=matrix.size(), col=matrix[0].size();
        vector<vector<int>> dp(row,vector<int>(col,0));

        int max_length=0;
        for (int i=0; i<row; i++) {
            for (int j=0; j<col; j++) {
                if (matrix[i][j]=='1') {
                    if (i==0 || j==0)
                        dp[i][j]=1;
                    else {
                        dp[i][j]=min(min(dp[i-1][j],dp[i][j-1]),dp[i-1][j-1])+1;
                    }
                    max_length=max(max_length,dp[i][j]);
                }
            }
        }
        return max_length*max_length;
    }
};