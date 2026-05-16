#include <algorithm>
#include <vector>
//
// Created by x12w on 2025/11/27.
//
class solution {
    public:
    int deleteAndEarn(vector<int>& nums) {
        int max_score=nums[0],score[1000]={0};
        for (auto num : nums) {
            score[num]+=num;
            if (score[num]>max_score) {
                max_score=score[num];
            }
        }
        if (max_score<3) {
            if (max_score==1) {
                return score[1];
            }
            else {
                return max(score[2],score[1]);
            }
        }
        score[3]+=score[1];
        for (int i=4;i<=max_score;i++) {
            score[i]+=max(score[i-2],score[i-3]);
        }
        return max(score[max_score],score[max_score-1]);
    }
};