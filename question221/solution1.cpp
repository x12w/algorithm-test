//
// Created by x12w on 2025/11/27.
//
#include<bits/stdc++.h>
using namespace std;


class solution {
    public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int row=matrix.size(), col=matrix[0].size();
        vector<vector<int>> dp(row,vector<int>(col,0));
        for (int i=0; i<row; i++) {
            for (int j=0; j<col; j++) {
                dp[i][j]=matrix[i][j]-'0';
            }
        }
        int max=0;

        for (int i=0;i<row;i++) {
            for (int j=0;j<col;j++) {

                if (dp[i][j]>0) {

                    if (max<dp[i][j]) {
                        max=dp[i][j];
                    }

                    if (i>0 && j>0 && dp[i-1][j-1]>0) {

                        for (int temp=1;temp<=dp[i-1][j-1];temp++) {

                            if (dp[i-temp][j]>0 && dp[i][j-temp]>0) {
                                dp[i][j]++;
                            }

                            else
                                break;
                        }

                        if (max<dp[i][j]) {
                            max=dp[i][j];
                        }
                    }

                }

            }
        }
        return max*max;
    }
};


int main() {
    vector<vector<char>> matrix(80,vector<char>(70,'1'));
    solution s;
    cout << s.maximalSquare(matrix) << endl;
}