class Solution {
public:
    int strangePrinter(string s) {
        int n = s.size();
        vector dp(n, vector<int>(n, n));
        for (int i = 1; i <= n; i++) {
            for (int l = 0; l <= n - i; l++) {
                int r = l + i - 1;
                int j = -1;
                for (int i = l; i < r; i++) {
                    if (s[i] != s[r] && j == -1) {
                        j = i;
                    }
                    if (j != -1) {
                        dp[l][r] = min(dp[l][r], 1 + dp[j][i] + dp[i + 1][r]);
                    }
                }
                
                if (j == -1) {
                    dp[l][r] = 0;
                }
            }
        }
        
        return dp[0][n - 1] + 1;
    }
};