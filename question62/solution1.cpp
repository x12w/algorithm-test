#include <vector>
//
// Created by x12w on 2025/11/27.
//
#include <iostream>

class solution {
    public:
    int uniquePaths(int m, int n) {
        int distance=m+n-2,result[10001];
        result[0]=1;
        for (int i=1; i<=distance; i++) {
            for (int j=((i>=n)?i-n+1:0); j<=i && j<m; j++) {
                if (j==0) {
                    result[j*n+i-j]=result[j*n+i-j-1];
                    std::cout << result[j*n+i-j] << "\t";
                    continue;
                }
                if (j==i) {
                    result[j*n+i-j]=result[(j-1)*n+i-j];
                    std::cout << result[j*n+i-j] << "\t";
                    continue;
                }
                result[j*n+i-j]=result[(j-1)*n+i-j]+result[j*n+i-j-1];
                std::cout << result[j*n+i-j] << "\t";
            }
            std::cout << std::endl;
        }
        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                std::cout << result[i*n+j] << "\t";
            }
            std::cout << std::endl;
        }
        return result[m*n-1];
    }
};

int main() {
    int m, n;
    std::cin >> m >> n;
    solution solution1;
    std::cout << solution1.uniquePaths(m, n) << std::endl;
}