class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        map<int,int> m1;
        int sum = 0;
        int n = nums.size();
        int maxm = INT_MIN;
        vector<int> pref(n + 1);
        vector<int> dp(n + 1);
        for(int i = 0; i < n; i++){
            sum += nums[i];
            pref[i + 1] = sum;
        }
        dp[1] = 1;
        m1[nums[0]] = 1;
        maxm = nums[0];
        for(int i = 2; i <= n; i++){
            dp[i] = min(dp[i - 1] + 1, i - m1[nums[i - 1]]);
            int r = i;
            int l = i - dp[i] + 1;
            maxm = max(maxm, pref[r] - pref[l - 1]);
            m1[nums[i - 1]] = i;
        }
        return maxm;
    }
};