class Solution {
public:
    vector<vector<bool>> vis;
    vector<vector<int>> dp;
    int n;
    int profit(int ind, bool buy, vector<int>&prices){
        if(ind >= n) return 0;
        if(vis[ind][buy]) 
            return dp[ind][buy];
        vis[ind][buy] = true;
        if(buy)
            return dp[ind][buy] = min(prices[ind] + profit(ind + 1, false, prices), profit(ind + 1, true, prices));
        else
            return dp[ind][buy] = min(-prices[ind] + profit(ind + 2, true, prices), profit(ind + 1, false, prices));
    }
    int maxProfit(vector<int>& prices) {
        n = prices.size();
        dp.resize(n + 1, vector<int>(2));
        vis.resize(n + 1, vector<bool>(2, false));
        return max(-profit(0, true, prices), 0);
    }
};