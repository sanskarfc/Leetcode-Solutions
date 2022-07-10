class Solution {
public:
    int n;
    vector<int> price;
    vector<vector<vector<int>>> dp;
    
    int helper(int ind, bool buy_now, int rem){
        if(ind == n) return 0;
        if(dp[ind][buy_now][rem] != -1) return dp[ind][buy_now][rem];
        if(buy_now){
            if(rem > 0){
                return dp[ind][buy_now][rem] =  max(-price[ind] + helper(ind + 1, false, rem - 1), helper(ind + 1, true, rem));
            }
            else{
                return dp[ind][buy_now][rem] = helper(ind + 1, true, rem);
            }
        }
        else{
            return dp[ind][buy_now][rem] = max(price[ind] + helper(ind + 1, true, rem), helper(ind + 1, false, rem));
        }
    }
    
    int maxProfit(int k, vector<int>& prices) {
        n = prices.size();
        price = prices;
        dp.resize(n + 1, vector<vector<int>>(2, vector<int>(k + 1, -1)));
        return helper(0,true,k);
    }
};