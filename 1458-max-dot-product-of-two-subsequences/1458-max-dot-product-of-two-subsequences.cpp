class Solution {
public:
    vector<int> nums1, nums2;
    vector<vector<int>> dp;
    
    int helper(int i, int j){
        if(i < 0 || j < 0) return 0;
        if(dp[i][j] != INT_MIN) return dp[i][j];
        return dp[i][j] = max({nums1[i]*nums2[j] + helper(i - 1, j - 1), helper(i - 1,j), helper(i, j - 1)});
    }
    
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        this->nums1 = nums1;
        this->nums2 = nums2;
        int n = nums1.size();
        int m = nums2.size();
        dp.resize(n + 1, vector<int>(m + 1, INT_MIN));
        int ans = helper(n - 1,m - 1);
        cout << "ans: " << ans << endl;
        if(ans == 0){
            int maxm = INT_MIN;
            for(int i = 0; i < n; i++){
                for(int j = 0; j < m; j++) maxm = max(maxm, nums1[i] * nums2[j]);
            }
            return maxm;
        }
        return ans;
    }
};