class Solution {
public:
    
    int ans;
    
    void merge(int l, int r, vector<int>&nums){
        int mid = (l + r)/2;
        int i = l;
        int j = mid + 1;
        while(i <= mid && j <= r){
            if((long long int)nums[i] > (long long int)2 * (long long int)nums[j]){
                ans += (mid - i + 1);
                j++;
            }
            else{
                i++;
            }
        }
        sort(nums.begin() + l, nums.begin() + r + 1);
    }
    
    void mergeSort(int l, int r, vector<int>&nums){
        if(l == r) return;
        int mid = (l + r)/2;
        mergeSort(l, mid, nums);
        mergeSort(mid + 1, r, nums);
        merge(l, r, nums);
        return;
    }
    
    int reversePairs(vector<int>& nums) {
        // x if current
        // we need count of greater than 2x that occured behind 
        // will use merge sort method
        int n = nums.size();
        ans = 0;
        mergeSort(0, n - 1, nums);
        return ans;
    }
};