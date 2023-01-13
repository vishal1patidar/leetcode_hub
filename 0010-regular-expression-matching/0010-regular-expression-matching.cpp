class Solution {
public:
    bool solve(string &s, string &p, int i, int j){
        if(i >= s.size() && j >= p.size()) return true;
        if(j >= p.size()) return false;

        bool ans = false;
        bool match = ( i < s.size() ) && (s[i] == p[j] || p[j] == '.');

        if(j+1 < p.size() && p[j+1] == '*'){
            ans = ( match && solve(s, p, i+1, j) ) || solve(s, p, i, j+2);
        }
        else if(match){
            ans = solve(s, p, i+1, j+1);
        }

        return ans;
    }

    bool solveMem(string &s, string &p, int i, int j, vector<vector<int>> &dp){
        if(i >= s.size() && j >= p.size()) return true;
        if(j >= p.size()) return false;

        if(dp[i][j] != -1){
            return dp[i][j];
        }

        bool ans = false;
        bool match = ( i < s.size() ) && (s[i] == p[j] || p[j] == '.');

        if(j+1 < p.size() && p[j+1] == '*'){
            ans = ( match && solveMem(s, p, i+1, j, dp) ) || solveMem(s, p, i, j+2, dp);
        }
        else if(match){
            ans = solveMem(s, p, i+1, j+1, dp);
        }

        return dp[i][j] = ans;
    }

    bool isMatch(string s, string p) {
        vector<vector<int>> dp(s.size()+1, vector<int>(p.size(), -1));
        return solveMem(s, p, 0, 0, dp);
    }
};