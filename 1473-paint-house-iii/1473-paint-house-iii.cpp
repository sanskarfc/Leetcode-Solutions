class Solution {
public:
    int n, m, target;
    vector<vector<int>> cost;
    vector<int> house;
    vector<vector<vector<long>>> cache;
    
    long helper(int ind, int prev_col, int grp){
        if(ind == m){
            if(grp == target) return 0;
            else return INT_MAX;
        }
        if(cache[ind][prev_col][grp] != -1) return cache[ind][prev_col][grp];
        long ans = INT_MAX;
        if(house[ind] != 0){
            if(prev_col + 1 == house[ind]){
                return cache[ind][prev_col][grp] = helper(ind + 1, prev_col, grp);   
            }
            else{
                return cache[ind][prev_col][grp] = helper(ind + 1, house[ind] - 1, grp + 1);   
            }    
        }
        for(int col = 0; col < n; col++){
            if(prev_col == col){
                ans = min(ans, cost[ind][col] + helper(ind + 1, col, grp));
            }
            else{
                ans = min(ans, cost[ind][col] + helper(ind + 1, col, grp + 1));
            }
        }
        return cache[ind][prev_col][grp] = ans;
    }
    
    int minCost(vector<int>& houses, vector<vector<int>>& costt, int mm, int nn, int targett) {
        m = mm; n = nn; target = targett; cost = costt; house = houses; // dumb stuff
        cache.resize(105, vector<vector<long>>(30, vector<long>(105,-1)));  // intialise
        int ans = helper(0,24,0);  // return
        if(ans == INT_MAX) return -1;
        else return ans;
    }
};