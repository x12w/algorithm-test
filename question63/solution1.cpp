//
// Created by x12w on 2025/11/27.
//
#include <bits/stdc++.h>
using namespace std;

class solution {
    public:
    int uniquePathWithObstacles(vector<vector<int>> &obstacleGrid) {
        int row=obstacleGrid.size()-1,column=obstacleGrid[0].size()-1,distance=row+column;
        if (obstacleGrid[row][column]==1 || obstacleGrid[0][0]==1) {
            return 0;
        }
        obstacleGrid[0][0]=-1;
        for (int i=1; i<=distance; i++) {
            for (int j=((i>column)?i-column:0); j<=i && j<=row ; j++) {
                if (obstacleGrid[j][i-j]==1) {
                    continue;
                }
                if (j==0) {
                    if (obstacleGrid[j][i-j-1]!=1) {
                        obstacleGrid[j][i-j]+=obstacleGrid[j][i-j-1];
                    }
                    continue;
                }
                if (j==i) {
                    if (obstacleGrid[j-1][i-j]!=1) {
                        obstacleGrid[j][i-j]+=obstacleGrid[j-1][i-j];
                    }
                    continue;
                }
                if (obstacleGrid[j][i-j-1]!=1) {
                    obstacleGrid[j][i-j]+=obstacleGrid[j][i-j-1];
                }
                if (obstacleGrid[j-1][i-j]!=1) {
                    obstacleGrid[j][i-j]+=obstacleGrid[j-1][i-j];
                }
            }
        }
        return -obstacleGrid[row][column];
    }
};


int main() {
    vector<vector<int>> grid = {{1}};
    solution solution1;
    int result=solution1.uniquePathWithObstacles(grid);
    for (auto &row : grid) {
        for (auto &col : row) {
            cout << col << " ";
        }
        cout << endl;
    }
    cout << result << endl;
}