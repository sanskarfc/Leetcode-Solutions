class Solution {
public:
    const int INF = 99999999;
    
    vector<vector<pair<int,int>>> adj;  // adjacency list
    vector<int> incoming; // counts the number of incoming edges into the node
    vector<int> dist;     // shortest distance from psuedo node
    
    void dijkstra(int src){
        priority_queue< pair<int,int>, vector <pair<int,int>> , greater<pair<int,int>> > pq;
        pq.push(make_pair(0, src));
        dist[src] = 0;
        while (!pq.empty()){
            int u = pq.top().second;
            pq.pop();
            for (int i = 0; i < (int)adj[u].size(); i++){
                int v = adj[u][i].first;
                int weight = adj[u][i].second;
                if (dist[v] > dist[u] + weight){
                    dist[v] = dist[u] + weight;
                    pq.push(make_pair(dist[v], v));
                }
            }
        }
    }
    
    int shortestPath(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        // transforming this 2D matrix into 1D matrix of nodes
        adj.resize(n * m + 1);
        incoming.resize(n * m + 1, 0);
        dist.resize(n * m + 1, INF);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                int node = i * m + j;
                if(i - 1 >= 0){     // checking if top node is valid
                    adj[node].push_back({(i - 1)*m + j, grid[i - 1][j]});
                }
                if(i + 1 < n){      // checking if down node is valid
                    adj[node].push_back({(i + 1)*m + j, grid[i + 1][j]});
                }
                if(j + 1 < m){      // checking if right node is valid
                    adj[node].push_back({i*m + j + 1, grid[i][j + 1]});
                }
                if(j - 1 >= 0){     // checking if left node is valid
                    adj[node].push_back({i*m + j - 1, grid[i][j - 1]});
                }
            }
        }
        dijkstra(0);        // calling dijkstra function
        return dist[n * m - 1];
    }
    
    int minimumObstacles(vector<vector<int>>& grid) {
        return shortestPath(grid);
    }
};