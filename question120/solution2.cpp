#include <vector>
//
// Created by x12w on 2025/11/27.
//
class solution {
    int minimumTotal(vector<vector<int> >&triangle) {
        for (int i=triangle.size()-2;i>=0;i--) {
            for (int j=0;j<=i;j++) {
                triangle[i][j]+=min(triangle[i+1][j],triangle[i+1][j+1]);
            }
        }
        return triangle[0][0];
    }
};