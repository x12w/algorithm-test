//
// Created by x12w on 2025/11/26.
//
class solution {
    public:
    int tribonacci(int n) {
        int dp[38];
        dp[0] = 0;
        dp[1]=dp[2]=1;
        if (n>2) {
            for (int i = 3; i <= n; i++) {
                dp[i]=dp[i-3]+dp[i-2]+dp[i-1];
            }
        }
        return dp[n];
    }
};