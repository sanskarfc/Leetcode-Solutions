// bruh this took too long, i hate this

class Solution {
public:
    int largestPathValue(string C, vector<vector<int>>& edges) {
        int n = C.length();
        int m = edges.size();
        int ans = 0;
        vector<vector<int>> g(n + 1);
        vector<vector<int>> dp(n + 1, vector<int>(26,0));
        vector<int> indeg(n + 1, 0);
        vector<int> order; //Stores the Topological Order
        
        for (auto &e : edges) {
            g[e[0]].push_back(e[1]); // build graph
            indeg[e[1]]++; // count indegrees
        }
        
        queue<int> q;
        for(int i = 0; i < n; i++){
            if(indeg[i] == 0){
                q.push(i);
                dp[i][C[i] - 'a'] = 1;
            }
        }
        
        ans = 0;
        
        while(!q.empty()){
            int u = q.front();
            q.pop();
            order.push_back(u);
            for(int i = 0; i < 26; i++) ans = max(ans, dp[u][i]);
            for(auto v : g[u]){
                for(int i = 0; i < 26; i++){
                    dp[v][i] = max(dp[v][i], dp[u][i] + (C[v] - 'a' == i));
                }
                indeg[v]--;
                if(!indeg[v]) q.push(v);
            }
        }
        return ((int)order.size() == n) ? ans : -1;
    }
};