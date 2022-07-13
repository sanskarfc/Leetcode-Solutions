class Solution {
public:
    int n;
    vector<int> pref;
    int carpetLen;
    vector<vector<int>> dp;
    int helper(int ind, int left){
        if(ind >= n) return 0;
        if(dp[ind][left] != -1) return dp[ind][left];
        if(left > 0){
            int place;
            if(ind == 0) place = pref[min(n - 1, ind + carpetLen - 1)] + helper(ind + carpetLen, left - 1);
            else place = pref[min(n - 1, ind + carpetLen - 1)] - pref[ind - 1] + helper(ind + carpetLen, left - 1);
            int not_place = helper(ind + 1, left);
            return dp[ind][left] = max(not_place, place);
        }
        else return dp[ind][left] = 0;
    }
    int minimumWhiteTiles(string floor, int numCarpets, int carpetLen) {
        // states --> number of carpets left, current index
        n = floor.size();
        dp.resize(n + 5, vector<int>(numCarpets + 5, -1));
        this->carpetLen = carpetLen;
        int white = 0;
        for(int i = 0; i < n; i++){
            white += (floor[i] == '1');
            pref.push_back(white);
        }
        int covers = helper(0,numCarpets);
        return (white - covers);
     }
};