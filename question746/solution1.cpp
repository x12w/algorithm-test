#include <vector>
//
// Created by x12w on 2025/11/26.
//
class solution {
    public:
    int minCostClimbingStairs(vector<int>& cost) {
        int dp[1001],length=cost.size();
        dp[0]=dp[1]=0;
        for (int i = 2; i <= length; i++) {
            int min_index=(dp[i-1]+cost[i-1]>dp[i-2]+cost[i-2])?i-2:i-1;
            dp[i]=dp[min_index]+cost[min_index];
        }
        return dp[length];
    }
};