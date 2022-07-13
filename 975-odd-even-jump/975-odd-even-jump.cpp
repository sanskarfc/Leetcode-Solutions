class Solution {
public:
    int oddEvenJumps(vector<int>& arr) {
        int n = arr.size();
        set<pair<int,int>> s1;
        vector<vector<bool>> dp(n + 1, vector<bool>(2,false));
        dp[n - 1][0] = true;
        dp[n - 1][1] = true;
        s1.insert({arr[n - 1], n - 1});
        for(int i = n - 2; i >= 0; i--){
            cout << "curr: " << arr[i] << endl;
            auto it = s1.lower_bound({arr[i],0});
            if(it != s1.end()){
                dp[i][1] = dp[(*it).second][0];
            }
            it = s1.upper_bound({arr[i],INT_MAX});
            if(it == s1.begin()){
                cout << "begin :[" << endl;
                dp[i][0] = false;
            }
            else{
                it--;
                int val = (*it).first;
                cout << "val: " << val << endl;
                it = s1.lower_bound({val,0});
                dp[i][0] = dp[(*it).second][1];
            }
            cout << "dp[i][0]: " << dp[i][0] << endl;
            cout << "dp[i][1]: " << dp[i][1] << endl;
            cout << endl;
            s1.insert({arr[i],i});
        }
        int ans = 0;
        for(int i = 0; i < n; i++) ans += dp[i][1];
        return ans;
    }
};