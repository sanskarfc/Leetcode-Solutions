class Solution {
public:
    bool splitArraySameAverage(vector<int>& nums) {
        int n = nums.size();
        if(n <= 1) return false;
        int sum = 0;
        for(auto x: nums) sum += x;
        vector<int> dp(sum + 1, 0);
        dp[nums[0]] = 2;
        for(int i=1; i<n; i++) {
            for(int s = sum - nums[i]; s >= 0; s--) {
                if(dp[s]) dp[s + nums[i]] |= (dp[s]<<1);
            }
            dp[nums[i]] |= 2;
        }
        for(int len = 1; len < n; len++) {
            if((sum * len) % n == 0 && ((1 << len) & dp[(sum*len)/n])) {
                return true;
            }
        }
        return false;
    }
};