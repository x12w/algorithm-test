#include <algorithm>
//
// Created by x12w on 2025/11/26.
//
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        for (int i = 2; i <= cost.size()-1; i++) {
            cost[i]+=min(cost[i-1],cost[i-2]);
        }
        if (cost.size()<2)
            return 0;
        else
            return min(cost[cost.size()-1],cost[cost.size()-2]);
    }
};