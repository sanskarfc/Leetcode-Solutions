class Solution {
public:
    vector<bool> cache;
    vector<bool> vis;
    map<string, bool> possible;
    set<int> len;
    int m;
    string s;
    
    bool helper(int ind){
        if(ind == m) return 1;
        if(vis[ind]){
            return cache[ind];
        }
        vis[ind] = true;
        bool ans = false;
        for(auto l : len){
            if(ind + l - 1 < m){
                if(possible[s.substr(ind, l)]){
                    ans = ans | helper(ind + l);
                }
            }
        }
        return ans;
    }
    
    int wordBreak(string A, vector<string> &B) {
        int n = B.size();
        s = A;
        m = A.length();
        for(int i = 0; i < n; i++){
            possible[B[i]] = true;
            len.insert(B[i].length());
        }
        cache.resize(2000);
        vis.resize(2000, false);
        return helper(0);
    }
};