class Solution {
public:
    int consecutiveNumbersSum(int n) {
        set<pair<int,int>> s1;
        n = n * 2;
        for(int i = 1; i * i <= n; i++){
            if(n % i == 0){
                int a = i;
                int b = n/i;
                if(a > b) swap(a,b);
                if((a + b - 1) % 2 == 0 && (b - a - 1) % 2 == 0){
                    int x = (a + b - 1)/2;
                    int y = (b - a - 1)/2;
                    if(x > y) swap(x,y);
                    s1.insert({x,y});
                }
            }
        }
        return s1.size();
    }
};