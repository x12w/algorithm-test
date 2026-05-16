#include <algorithm>
//
// Created by x12w on 2025/11/27.
//
class solution {
    public:
    int minFallingPathSum(vector<vector<int>> &matrix) {
        int n = matrix.size();
        for (int i=1;i<n;i++) {
            for (int j=0;j<n;j++) {
                if (j==0) {
                    matrix[i][j]+=min(matrix[i-1][j],matrix[i-1][j+1]);
                    continue;
                }
                if (j==n-1) {
                    matrix[i][j]+=min(matrix[i-1][j-1],matrix[i-1][j]);
                    continue;
                }
                matrix[i][j]+=min(min(matrix[i-1][j-1],matrix[i-1][j]),matrix[i-1][j+1]);
            }
        }
        int min_val=matrix[n-1][0];
        for (int i=0;i<n;i++) {
            if (matrix[n-1][i]<min_val)
                min_val=matrix[n-1][i];
        }
        return min_val;
    }
};