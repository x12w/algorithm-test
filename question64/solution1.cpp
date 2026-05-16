#include <algorithm>
//
// Created by x12w on 2025/11/27.
//
class solution {
    public:
    int minPathSum(vector<vector<int>> &grid) {
        int m=grid.size(),n=grid[0].size();
        for (int distance=1; distance<=m+n-2; distance++) {
            for (int line=((distance>=n)?distance-n+1:0); line<m && line<=distance;line++) {
                if (line==0) {
                    grid[line][distance-line]+=grid[line][distance-line-1];
                    continue;
                }
                if (line==distance) {
                    grid[line][distance-line]+=grid[line-1][distance-line];
                    continue;
                }
                grid[line][distance-line]+=min(grid[line-1][distance-line],grid[line][distance-line-1]);
            }
        }
        return grid[m-1][n-1];
    }
};
