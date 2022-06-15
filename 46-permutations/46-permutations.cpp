class Solution {
public:
    int n;
    vector<vector<int>> ans;
    void helper(int l, vector<int> &nums){
	        if(l == n - 1){
	            ans.push_back(nums);
	            return;
	        }
	        for(int i = l; i < n; i++){
	            swap(nums[i], nums[l]);
	            helper(l + 1, nums);
	            swap(nums[i], nums[l]);
	        }
	    }
    vector<vector<int>> permute(vector<int>& nums) {
        n = nums.size();
        helper(0, nums);
        return ans;
    }
};