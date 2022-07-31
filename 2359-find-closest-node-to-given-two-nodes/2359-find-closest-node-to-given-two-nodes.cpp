class Solution {
public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        if(node1 == node2) return node1;
        int n = edges.size();
        vector<vector<int>> adj(n + 1);
        vector<bool> visited1(n + 1, false);
        vector<bool> visited2(n + 1, false);
        queue<int> q1;
        queue<int> q2;
        vector<int> lvl1(n + 1, INT_MAX);
        vector<int> lvl2(n + 1, INT_MAX);
        lvl1[node1] = 0;
        lvl2[node2] = 0;
        q1.push(node1);
        q2.push(node2);
        visited1[node1] = true;
        visited2[node2] = true;
        for(int i = 0; i < n; i++){
            if(edges[i] != -1){
                adj[i].push_back(edges[i]);
            }
        }
        while(!q1.empty()){
            int v = q1.front();
            q1.pop();
            for(auto x : adj[v]){
                if(!visited1[x]){
                    visited1[x] = true;
                    q1.push(x);
                    lvl1[x] = lvl1[v] + 1;
                }
            }
        }
        long long minm = INT_MAX;
        int minm_node = INT_MAX;
        while(!q2.empty()){
            int v = q2.front();
            q2.pop();
            if(max(lvl2[v], lvl1[v]) < minm){
                minm = max(lvl2[v], lvl1[v]);
                minm_node = v;
            }
            else if(max(lvl2[v], lvl1[v]) == minm){
                if(minm_node > v){
                    minm_node = v;
                }
            }
            for(auto x : adj[v]){
                if(!visited2[x]){
                    visited2[x] = true;
                    q2.push(x);
                    lvl2[x] = lvl2[v] + 1;
                }
            }
        }
        if(minm == INT_MAX) return -1;
        else return minm_node;
    }
};