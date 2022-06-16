class Solution {
public:
    int n;
    int cache[501][501]; 
    int solve(vector<int> &nums, int i, int j){
		if(i > j) return 0;
        if(i == j){
            int temp = nums[i];
            if(i - 1 >= 0) temp *= nums[i - 1];
            if(i + 1 < n) temp *= nums[i + 1];
            return temp;
        }
		if(cache[i][j] != -1) return cache[i][j];
        int ans = 0;
        for(int k = i; k <= j; k++){
            int temp = nums[k];
            if(j + 1 < n) temp *= nums[j + 1];
            if(i - 1 >= 0) temp *= nums[i - 1];
            temp += (solve(nums, i, k - 1) + solve(nums, k + 1, j));
            ans = max(ans, temp);
        }
        return cache[i][j] = ans;
    }
    
    int maxCoins(vector<int>& nums) {
        for(int i = 0; i <= 500; i++){
            for(int j = 0; j <= 500; j++){
                cache[i][j] = -1;    
            }
        }
		vector<int> arr;
        arr.push_back(1);
        for(int i = 0; i < nums.size(); i++){
            arr.push_back(nums[i]);
        }
        arr.push_back(1);
        n = arr.size();
        return solve(arr, 1, arr.size() - 2);
    }
};