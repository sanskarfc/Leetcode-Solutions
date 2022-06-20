class Solution {
public:
    // this problem can be easily solved using a segment tree in O(n log n) --> i'll try to implement it just for fun here
    static const int N = 100005;
    int a[N];
    int t[4 * N];
    vector<int> ans;
    
    void build(int v, int l, int r){
        if(l > r) return;
        if(l == r){
            t[v] = a[l];
            return;
        }
        int mid = (l + r)/2;
        build(2 * v, l, mid);
        build(2 * v + 1, mid + 1, r);
        t[v] = max(t[2 * v], t[2 * v + 1]);
    }
    
    // here,
    // l --> the left most 
    // r --> the right most
    // ql --> query left
    // qr --> query right
    
    int max_query(int v, int l, int r, int tl, int tr){
        if(l >= tl && r <= tr) return t[v];
        if(tr < l || tl > r) return INT_MIN;
        int mid = (l + r)/2;
        return max(max_query(2 * v, l, mid, tl, tr), max_query(2 * v + 1, mid + 1, r, tl, tr));
    }
    
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        // copying the array first
        for(int i = 0; i < n; i++) a[i] = nums[i];
        
        // building the segment tree
        build(1, 0, n - 1);
        
        for(int i = 0; i < n; i++){
            if(i + k - 1 < n) ans.push_back(max_query(1, 0, n - 1, i, i + k - 1));
            else break;
        }
        
        return ans;
    }
};