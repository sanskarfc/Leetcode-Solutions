class Solution {
public:
    multiset<char> alpha;
    map<char,int> score;
    int ans = 0;
    int tempans = 0;
    int n;
    
    void helper(int ind, vector<string> &words){
        // if a string can, move to next string and then backtrack
        
        // if a string cannot, backtrack and then move to the next string 
        int tempans2 = tempans;
        bool found = true;
        multiset<char> tempset;
        if(ind == n){
            ans = max(ans, tempans);
            return;
        }
        for(int i = 0; i < words[ind].size(); i++){
            if(alpha.find(words[ind][i]) != alpha.end()){
                alpha.erase(alpha.find(words[ind][i]));
                tempans += score[words[ind][i]];
                tempset.insert(words[ind][i]);
            }
            else{
                found = false;
                break;
            }
        }
        if(found){
            helper(ind + 1, words);
            for(auto x : tempset) alpha.insert(x);
            tempans = tempans2;
            helper(ind + 1, words);
        }
        else{
            for(auto x : tempset) alpha.insert(x);
            tempans = tempans2;
            helper(ind + 1, words);
        }
    }
    
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& sc) {
        for(char ch = 'a'; ch <= 'z'; ch++){
            score[ch] = sc[ch - 'a'];
        }
        for(auto ch : letters) alpha.insert(ch);
        n = words.size();
        helper(0, words);
        return ans;
    }
    
};