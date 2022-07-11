struct DSU{
    int connected;
    vector<int> par, sz;
    
    void init(int n)
    {
        par = sz = vector<int> (n + 1, 0);
        for(int i = 1; i <= n; i++){
            par[i] = i;
            sz[i] = 1;
        }
        connected = n;
    }
    
    int getPar(int u)
    {
        while(u != par[u])
        {
            par[u] = par[par[u]];
            u = par[u];
        }
        return u;
    }
    
    int getSize(int u)
    {
        return sz[getPar(u)];
    }
    
    void unite(int u, int v)
    {
        int par1 = getPar(u), par2 = getPar(v);
        
        if(par1 == par2)
            return;
        
        connected--;
        
        if(sz[par1] > sz[par2])
            swap(par1, par2);
        
        sz[par2] += sz[par1];
        sz[par1] = 0;
        par[par1] = par[par2];
    }
};

DSU dsu;

class Solution {    
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size() + 1;
        dsu.init(n);
        vector<int> ans(2, -1);
        for(int i = 0; i < n - 1; i++){
            int a = edges[i][0];
            int b = edges[i][1];
            if(dsu.getPar(a) == dsu.getPar(b)){
                ans[0] = a;
                ans[1] = b;
            }
            dsu.unite(a,b);
        }
        return ans;
    }
};