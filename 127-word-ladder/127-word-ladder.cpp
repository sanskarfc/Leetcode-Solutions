class Solution {
public:
    // i can make a graph --> and do dfs?
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int n = wordList.size();
        unordered_map<string,int> present;
        unordered_map<int,vector<int>> adj;
        map<int,int> vis;
        map<int,int> dis;
        for(int i = 0; i < n; i++){
            for(char ch = 'a'; ch <= 'z'; ch++){
                for(int j = 0; j < wordList[i].size(); j++){
                    string a1 = wordList[i].substr(0, j);
                    string a2 = wordList[i].substr(j + 1, n - j + 1);
                    string check = a1 + ch + a2;
                    if(present[check] > 0){
                        adj[i + 1].push_back(present[check]);
                        adj[present[check]].push_back(i + 1);
                    }
                }
            }
            present[wordList[i]] = i + 1;
        }
        for(char ch = 'a'; ch <= 'z'; ch++){
            for(int j = 0; j < beginWord.size(); j++){
                string a1 = beginWord.substr(0, j);
                string a2 = beginWord.substr(j + 1, n - j + 1);
                string check = a1 + ch + a2;
                if(present[check] > 0){
                    adj[0].push_back(present[check]);
                    adj[present[check]].push_back(0);
                }
            }
        }
        queue<int> q;
        q.push(0);
        dis[0] = 1;
        while(!q.empty()){
            int v = q.front();
            q.pop();
            vis[v] = true;
            for(auto x : adj[v]){
                if(vis[x]) continue;
                vis[x] = true;
                dis[x] = dis[v] + 1;
                q.push(x);
            }
        }
        if(present[endWord]){
            return dis[present[endWord]];
        }
        else return 0;
        
    }
};