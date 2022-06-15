class Solution {
public:
    int maxProduct(vector<int>& nums) {
        // dp[i] --> max subarray product ending at index i
        vector<int> dp(nums.size() + 1);
        vector<int> pd(nums.size() + 1);
        int maxm = nums[0];
        for(int i = 0; i < nums.size(); i++){
            dp[i] = nums[i];
            pd[i] = nums[i];
        }
        for(int i = 1; i < nums.size(); i++){
            pd[i] = min({pd[i], pd[i - 1] * nums[i], dp[i - 1] * nums[i]});
            dp[i] = max({dp[i], dp[i - 1] * nums[i], pd[i - 1] * nums[i]});
            maxm = max(maxm, dp[i]);
        }
        return maxm;
    }
};