class Solution {
public:
    int rob(vector<int>& nums) {
        // dp[i] --> max money we get till i-th index
        int n = nums.size();
        vector<int> dp(n + 1, 0);
        for(int i = 0; i < n; i++) dp[i] = nums[i];
        for(int i = 0; i < n; i++){
            if(i - 1 >= 0) dp[i] = max(dp[i], dp[i - 1]);
            if(i - 2 >= 0) dp[i] = max(dp[i], dp[i - 2] + nums[i]);
        }
        return dp[n - 1];
    }
};