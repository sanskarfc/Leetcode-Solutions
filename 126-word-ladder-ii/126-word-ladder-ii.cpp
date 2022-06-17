class Solution {
public:
    // i can make a graph --> and do bfs?
    vector<vector<string>> ans;
    unordered_map<string,int> present; 
    unordered_map<int,string> give;
    unordered_map<int,vector<int>> adj;
    map<int,int> vis;
    map<int,int> dis;
    vector<string> temp;
    
    void findPaths(int node){
        temp.push_back(give[node]);
        if(node == 0){
            reverse(temp.begin(), temp.end());
            ans.push_back(temp);
            return;
        }
        for(auto x : adj[node]){
            if(dis[x] == dis[node] - 1){
                vector<string> temp2 = temp;
                findPaths(x);
                temp = temp2;
            }
        }
    }
    
    void ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int n = wordList.size();
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
            give[i + 1] = wordList[i];
        }
        give[0] = beginWord;
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
        if(present[endWord]) findPaths(present[endWord]);
    }

    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        ladderLength(beginWord, endWord, wordList);
        return ans;
    }
};