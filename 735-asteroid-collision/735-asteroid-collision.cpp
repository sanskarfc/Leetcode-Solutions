class Solution {
public:
    vector<int> asteroidCollision(vector<int>& v1) {
        stack<int> s1;
        s1.push(v1[0]);
        vector<int> ans;
        int n = v1.size();
        for(int i = 1; i < n; i++){
            if(s1.empty()){
                s1.push(v1[i]);
            }
            else{
                if(v1[i] > 0){
                    s1.push(v1[i]);
                    continue;
                }
                // now we have v1[i] < 0
                bool exists = true;
                while(!s1.empty()){
                    if(s1.top() > 0){
                        if(s1.top() > abs(v1[i])) break;
                        else if(s1.top() == abs(v1[i])){
                            s1.pop();
                            exists = false;
                            break;
                        }
                        else s1.pop();
                    }
                    else{
                        s1.push(v1[i]);
                        break;
                    }
                }
                if(s1.empty() && exists) s1.push(v1[i]);
            }
        }
        while(!s1.empty()){
            ans.push_back(s1.top());
            s1.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};