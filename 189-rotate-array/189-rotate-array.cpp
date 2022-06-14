class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;
        int yo[n];
        for(int i = 0; i < n; i++){
            yo[i] = nums[i];
        }
        reverse(yo, yo + n - k);
        reverse(yo + n - k, yo + n);
        reverse(yo, yo + n);
        for(int i = 0; i < n; i++){
            nums[i] = yo[i];
        }
    }
};