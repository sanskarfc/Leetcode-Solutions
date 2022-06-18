class Solution {
public:
    
    static bool custom_sort(vector<int>&a, vector<int>&b){
        if(a[0] < b[0]) return true;
        else if(a[0] == b[0]){
            return a[1] < b[1];
        }
        else return false;
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        // sort according to start time of intervals and remove the intervals which end later
        sort(intervals.begin(), intervals.end(), custom_sort);
        int ans = 0;
        int n = intervals.size();
        vector<vector<int>> yo;
        yo.push_back(intervals[0]);
        for(int i = 1; i < n; i++){
            if(intervals[i][0] < (yo.back())[1]){
                if(intervals[i][1] > (yo.back())[1]) ans++;            
                else{
                    yo.pop_back();
                    yo.push_back(intervals[i]);
                    ans++;
                }
            }
            else yo.push_back(intervals[i]);
        }
        return ans;
    }
};