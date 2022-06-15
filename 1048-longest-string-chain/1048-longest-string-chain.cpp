class Solution {
public:
    static bool custom(string &a, string &b){
        return a.size() < b.size();
    }
    int longestStrChain(vector<string>& words) {
        // dp states --> current index
        sort(words.begin(), words.end(), custom);
        unordered_map<string,int> dp;
        int n = words.size();
        int maxm = 1;
        for(int i = 0; i < n; i++){
            string s = words[i];
            int nn = s.length();
            dp[s] = 1;
            for(int j = 0; j < nn; j++){
                string a1 = s.substr(0, j);
                string a2 = s.substr(j + 1, nn - (j + 1) + 1);
                string ab = a1 + a2;
                if(dp[ab] > 0) dp[s] = max(dp[s], dp[ab] + 1);
            }
            maxm = max(maxm, dp[s]);
        }
        return maxm;
    }
};