const int MOD = 1e9+7;

int dp[2][2][10][101];

class Solution {
    string SubtractOne (string s) {
        reverse(s.begin(), s.end());
        
        int first_non_zero = 0;
        while (s[first_non_zero] == '0') first_non_zero ++;
        
        s[first_non_zero] --;
        for (int j = 0; j < first_non_zero; j ++) s[j] = '9';
        
        while(s.back() == '0') s.pop_back();
        if (s.empty()) s = "0";
        
        reverse(s.begin(), s.end());
        return s;
    }
    
    int CountValid (bool is_smaller, bool is_started, int ind, int last, const string& s) {
        if (ind == s.length()) return 1;
        
        int &ans = dp[is_started][is_smaller][last][ind];
        if (ans != -1) return ans;
        
        ans = 0;
        int st = 0;
        int ed = is_smaller? 9 : (s[ind] - '0');
        
        for (int j = st; j <= ed; j ++) {
            if (is_started && abs(j - last) != 1) continue;
            
            bool new_is_started = is_started? true : (j != 0);
            bool new_is_smaller = is_smaller? true : (j != ed);
            
            ans = (ans + CountValid(new_is_smaller, new_is_started, ind+1, j, s)) % MOD;
        }
        return ans;
    }
    
public:
    int countSteppingNumbers(string low, string high) {
        int result = 0;
        
        memset (dp, -1, sizeof(dp));
        result = (result + CountValid(false, false, 0, 0, high)) % MOD;
        
        memset (dp, -1, sizeof(dp));
        result = (result - CountValid(false, false, 0, 0, SubtractOne(low)) + MOD) % MOD;
                  
        return result;
    }
};