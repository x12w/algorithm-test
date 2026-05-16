#include <vector>
//
// Created by x12w on 2025/11/27.
//
class solution {
    public:
    int minimumTotal(vector<vector<int>> &triangle) {
        for (int i=1; i<triangle.size(); i++) {
            for (int j=0; j<triangle[i].size(); j++) {
                if (j==0) {
                    triangle[i][j]+=triangle[i-1][j];
                    continue;
                }
                if (j==triangle[i].size()-1) {
                    triangle[i][j]+=triangle[i-1][j-1];
                    continue;
                }
                triangle[i][j]+=min(triangle[i-1][j-1],triangle[i-1][j]);
            }
        }
        int min_res=triangle[triangle.size()-1][0];
        for (auto i:triangle[triangle.size()-1]) {
            if (i<min_res) {
                min_res=i;
            }
        }
        return min_res;
    }
};