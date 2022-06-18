class Solution {
public:
    vector<vector<int>> adj;
    vector<int> dp;
    vector<int> sub;
    string s;
    void dfs(int node, int par){
        sub[node] = 1;
        for(auto x : adj[node]){
            if(x == par) continue;
            dfs(x, node);
            if(s[node] != s[x]) sub[node] = max(sub[node], sub[x] + 1);
        }
    }
    void dfs2(int node, int par){
        vector<int> yo;
        for(auto x : adj[node]){
            if(x == par) continue;
            if(s[node] != s[x]) yo.push_back(sub[x]);
        }
        sort(yo.begin(), yo.end(), greater<int>());
        int m = (int)yo.size();
        
        if(m == 0) dp[node] = 1;
        else if(m == 1) dp[node] = yo[0] + 1;
        else dp[node] = yo[0] + yo[1] + 1;
        
        for(auto x : adj[node]){
            if(x == par) continue;
            dfs2(x, node);
        }
    }
    int longestPath(vector<int>& parent, string t) {
        // for a node, we need --> longest path on the right including the current node
        // for a node, we need --> longest path on the left including the current node
        // final answer for a node is the sum of both the (paths + 1)
        int n = parent.size();
        adj.resize(n + 1);
        sub.resize(n + 1, 0);
        dp.resize(n + 1, 0);
        s = t;
        for(int i = 1; i < n; i++){
            adj[i].push_back(parent[i]);
            adj[parent[i]].push_back(i);
        }
        int maxm = 1;
        dfs(0,-1);
        dfs2(0,-1);
        for(int i = 0; i < n; i++) maxm = max(maxm, dp[i]);
        return maxm;
    }
};