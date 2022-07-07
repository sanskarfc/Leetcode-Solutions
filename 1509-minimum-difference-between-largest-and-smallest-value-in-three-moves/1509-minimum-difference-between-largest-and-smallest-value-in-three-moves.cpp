class Solution {
public:
    int minDifference(vector<int>& nums) {
        if((int)nums.size() <= 4) return 0;
        sort(nums.begin(), nums.end());
        int j = (int)nums.size() - 1;
        int minm = INT_MAX;
        for(int l = 0; l <= 3; l++){
            minm = min(minm, max(0, nums[j - (3 - l)] - nums[l]));
        }
        return minm;
    }
};