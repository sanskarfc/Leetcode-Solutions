class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        // sort according to ending index
        // shoot at the end point from starting to end and burst all the baloons that have that common area
        set<pair<int,int>> s1;
        int ans = 0;
        int siz = points.size();
        for(int i = 0; i < siz; i++){
            s1.insert({points[i][1], points[i][0]});
        }
        long long int prev = (long long int)INT_MAX + (long long int)1;
        while(!s1.empty()){
            int l = (*s1.begin()).second;
            int r = (*s1.begin()).first;
            if(prev >= (long long int)l && prev <= (long long int)r) s1.erase(s1.begin());
            else{
                ans++;
                prev = (long long int)r;
                s1.erase(s1.begin());
            }
        }
        return ans;
    }
};