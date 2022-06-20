class Solution {
public:
    vector<string> ans;
    set<int> len;
    set<string> possible;
    string temp;
    string s;
    int n;
    int m;
    
    void helper(int ind){
        if(ind > m) return;
        if(ind == m){
            ans.push_back(temp);
            return;
        }
        for(auto l : len){
            if(ind + l - 1 > m) continue;
            if( possible.find(s.substr(ind, l)) != possible.end() ) {
                string temp2 = temp;
                if(ind != 0) temp += " ";
                temp += s.substr(ind, l);
                helper(ind + l);
                temp = temp2;
            }
        }
    }
    
    vector<string> wordBreak(string t, vector<string>& wordDict) {
        n = wordDict.size();
        s = t;
        m = s.length();
        for(int i = 0; i < n; i++){
            len.insert(wordDict[i].length());
            possible.insert(wordDict[i]);
        }
        helper(0);
        return ans;
    }
};