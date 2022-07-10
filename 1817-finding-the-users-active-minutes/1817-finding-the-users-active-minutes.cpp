class Solution {
public:
    vector<int> findingUsersActiveMinutes(vector<vector<int>>& logs, int k) {
        set<pair<int,int>> s1;
        for(int i = 0; i < (int)logs.size(); i++){
            s1.insert({logs[i][0], logs[i][1]});
        }
        vector<int> v1;
        for(auto p : s1){
            v1.push_back(p.first);
        }
        vector<int> ans(k,0);
        int count = 0;
        int prev = v1[0];
        for(int i = 0; i < (int)v1.size(); i++){
            if(prev == v1[i]){
                count++;
            }
            else{
                ans[count - 1]++;
                count = 1;
                prev = v1[i];
            }
        }
        ans[count - 1]++;
        return ans;
    }
};