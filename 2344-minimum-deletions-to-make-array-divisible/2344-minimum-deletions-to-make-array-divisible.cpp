class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& numsDivide) {
        sort(nums.begin(), nums.end());
        int gcd = numsDivide[0];
        bool found = false;
        int minm = INT_MAX;
        for(int i = 0; i < (int)numsDivide.size(); i++) gcd = __gcd(gcd, numsDivide[i]);
        for(int i = 0; i < (int)nums.size(); i++){
            if(gcd % nums[i] == 0){
                found = true;
                minm = min(minm, nums[i]);
            }
        }
        if(!found) return -1;
        int ind = lower_bound(nums.begin(), nums.end(), minm) - nums.begin();
        return ind;
    }
};