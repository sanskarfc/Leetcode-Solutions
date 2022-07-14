class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        // this question resolves to just finding the next smaller element on the right AND left
        int maxm = 0;
        vector<int> v1 = heights;
        int n = v1.size();
        if(n == 1){
            return v1[0];
        }
        stack<int> s1;
        stack<int> s2;
        vector<int> left(n);
        vector<int> right(n);
        for(int i = 0; i < n; i++){
            if(s1.empty()) left[i] = -1;
            else{
                int h;
                h = v1[s1.top()];
                while(h >= v1[i]){
                    s1.pop();
                    if(s1.empty()) break;
                    h = v1[s1.top()];
                }
                if(s1.empty()) left[i] = -1;
                else left[i] = s1.top();
            }
            s1.push(i);
        }
        reverse(v1.begin(), v1.end());
        for(int i = 0; i < n; i++){
            if(s2.empty()) right[i] = -1;
            else{
                int h;
                h = v1[s2.top()];
                while(h >= v1[i]){
                    s2.pop();
                    if(s2.empty()) break;
                    h = v1[s2.top()];
                }
                if(s2.empty()) right[i]  = -1;
                else right[i] = s2.top();
            }
            s2.push(i);
        }
        for(int i = 0; i < n; i++){
            right[i] = n - 1 - right[i];
        }
        reverse(right.begin(), right.end());
        reverse(v1.begin(), v1.end());
        for(int i = 0; i < n; i++){
            maxm = max(maxm, (right[i] - left[i] - 1) * v1[i]);
        }
        return maxm;
    }
};