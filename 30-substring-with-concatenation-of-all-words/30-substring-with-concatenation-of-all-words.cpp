const int MOD = 1000000007;
const int P = 31;

// curtsy: ashishgup's github
struct Hashs 
{
	vector<int> hashs;
	vector<int> pows;
	int P;
	int MOD;

	Hashs() {}

	Hashs(string &s, int P, int MOD) : P(P), MOD(MOD) 
	{
		int n = s.size();
		pows.resize(n + 1, 0);
		hashs.resize(n + 1, 0);
		pows[0] = 1;
		for(int i = n - 1; i >= 0; i--) 
		{
			hashs[i] = (1LL * hashs[i + 1] * P + s[i] - 'a' + 1) % MOD;
			pows[n - i] = (1LL * pows[n - i - 1] * P) % MOD;
		}
		pows[n] = (1LL * pows[n - 1] * P) % MOD;
	}

	int get_hash(int l, int r) 
	{
		int ans = hashs[l] + MOD - (1LL * hashs[r + 1] * pows[r - l + 1]) % MOD;
		ans %= MOD;
		return ans;
	}
};

//Problem 1: https://codeforces.com/contest/633/problem/C
//Solution 1: https://codeforces.com/contest/633/submission/42330829

//Problem 2: https://atcoder.jp/contests/abc141/tasks/abc141_e
//Solution 2: https://atcoder.jp/contests/abc141/submissions/7523234

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int m = words.size();
        int n = s.length();
        vector<Hashs> h(m);
        multiset<int> s1;
        int l = words[0].length();
        for(int i = 0; i < m; i++){
            h[i] = Hashs(words[i], P, MOD);
            s1.insert(h[i].get_hash(0, l - 1));
        }
        vector<int> ans;
        Hashs h1 = Hashs(s, P, MOD);
        for(int i = 0; i <= n - m*l; i++){
            // now check if all are present
            multiset<int> s2 = s1;
            int count = 0;
            for(int j = 0; j < m; j++){
                int num = h1.get_hash(i + j*l, i + (j + 1)*l - 1);
                auto it = s2.find(num);
                if(it != s2.end()){
                    s2.erase(it);
                }
                else break;
                count++;
            }
            cout << endl;
            if(count == m) ans.push_back(i);
        }
        return ans;
    }
};