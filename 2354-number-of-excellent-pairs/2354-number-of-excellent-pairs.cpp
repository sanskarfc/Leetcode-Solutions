class Solution {
public:
    long long countExcellentPairs(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> bits;
        set<int> s1;
        for(int i = 0; i < n; i++){
            int count = 0;
            bool yo = false;
            if(s1.find(nums[i]) == s1.end()) yo = true;
            s1.insert(nums[i]);
            while(nums[i] != 0){
                if(nums[i] % 2 == 1) count++;
                nums[i] /= 2;
            }
            if(yo) bits.push_back(count);
        }
        int m = bits.size();
        sort(bits.begin(), bits.end());
        long long ans = 0;
        for(int i = 0; i < m; i++){
            int ind = lower_bound(bits.begin(), bits.end(), k - bits[i]) - bits.begin();
            if(ind == n) continue;
            ans += (m - ind);
        }
        return ans;
    }
};