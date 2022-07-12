class Solution {
public:
    int timer, n, l;
    vector<vector<int>> adj;
    vector<int> tin, tout,parent,subXOR,val;
    void dfs(int v, int p){
        tin[v] = ++timer;
        for (int u : adj[v]) {
            if (u != p) dfs(u, v);
        }
        tout[v] = ++timer;
    }
    void preprocess(int root) {
        tin.resize(n + 1);
        tout.resize(n + 1);
        timer = 0;
        l = ceil(log2(n));
        dfs(root, root);
    }
    void dfs1(int node, int par){
        subXOR[node] = val[node];
        for(auto x : adj[node]){
            if(x == par) continue;
            parent[x] = node; 
            dfs1(x, node);
            subXOR[node] = (subXOR[node] ^ subXOR[x]);
        }
    }
    int minimumScore(vector<int>& nums, vector<vector<int>>& edges) {
        n = nums.size();
        val = nums;
        adj.resize(n + 1);
        subXOR.resize(n + 1);
        parent.resize(n + 1);
        for(int i = 0; i < n - 1; i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        preprocess(0);
        int minm = INT_MAX;
        dfs1(0,0);
        for(int i = 0; i < n - 1; i++){
            for(int j = i + 1; j < n - 1; j++){
                int val1, val2, val3;
                int node1 = edges[i][0];
                int node2 = edges[i][1];
                if(parent[node1] == node2) swap(node1, node2);
                int node3 = edges[j][0];
                int node4 = edges[j][1];
                if(parent[node3] == node4) swap(node3,node4);
                if(tin[node4] <= tin[node2] && tout[node4] >= tout[node2]){
                    swap(node1, node3);
                    swap(node2, node4);
                }
                if(tin[node2] <= tin[node4] && tout[node2] >= tout[node4]){
                    val1 = (subXOR[node2] ^ subXOR[node4]);
                    val2 = subXOR[node4];
                    val3 = (subXOR[0] ^ val1 ^ val2);
                }
                else{
                    val1 = subXOR[node2];
                    val2 = subXOR[node4];
                    val3 = (subXOR[0] ^ val1 ^ val2);
                }
                minm = min(minm, max({val1,val2,val3}) - min({val1, val2, val3}));
            }
        }
        return minm;
    }
};