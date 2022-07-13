class TreeAncestor {
public:
    int n, l;
    vector<vector<int>> adj;
    vector<vector<int>> up;

    void dfs(int v, int p){
        up[v][0] = p;
        for (int i = 1; i <= l; ++i){
            up[v][i] = up[up[v][i-1]][i-1];
            if (up[v][i] == -1) break;
        }
        for (int u : adj[v]) {
            if (u != p) dfs(u, v);
        }
    }
    
    void preprocess(int root) {
        l = ceil(log2(n));
        up.assign(n, vector<int>(l + 1,-1));
        for(auto x : adj[0]) dfs(x,root);
    }
    
    TreeAncestor(int nn, vector<int>& parent) {
        n = nn;
        adj.resize(n + 1);
        for(int i = 0; i < n; i++){
            if(parent[i] != -1){
                adj[parent[i]].push_back(i);
                adj[i].push_back(parent[i]);
            }
        }
        preprocess(0);
    }
    
    int getKthAncestor(int node, int k) {
        for (int i = 0; i <= l; i++){
            if (k & (1 << i)){
                node = up[node][i];
                if (node == -1) break;
            }
        }
        return node;
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */