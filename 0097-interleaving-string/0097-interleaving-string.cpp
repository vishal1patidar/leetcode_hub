class Solution {
public:
    bool solve(int i, int j, int k, string s1, string s2, string s3, vector<vector<int>>&dp)
    {
        if(k==s3.length()) //base case - a - if s3 is completely traversed
            return true;
        if(dp[i][j]!=-1) // searching in dp table
            return dp[i][j];
        /* base case - b - if s1 is finished and current 
        character of s2 doesn't matches with s3's current character. */
        if(i==s1.length() && s2[j]!=s3[k])
            return false;
        /* base case - c - if s2 is finished and current 
        character of s1 doesn't matches with s3's current character. */
        if(j==s2.length() && s1[i]!=s3[k])
            return false;
        //base case - d - If neither s1[i] nor s2[j] matches with s3[k], return false
        if(s1[i]!=s3[k] && s2[j]!=s3[k])
            return false;
//RECURSION
    //a.
        if(s1[i]==s3[k] && s2[j]!=s3[k])
            return dp[i][j]=solve(i+1, j, k+1, s1, s2, s3, dp);
    //b.
        if(s1[i]!=s3[k] && s2[j]==s3[k])
            return dp[i][j]=solve(i, j+1, k+1, s1, s2, s3, dp);
    //c.
        else
            return dp[i][j]=(solve(i+1, j, k+1, s1, s2, s3, dp) || solve(i, j+1, k+1, s1, s2, s3, dp));
    }
    bool isInterleave(string s1, string s2, string s3) {
        //if length of string s3 is less than lengthof s1+s2 string then, interleaving not possible
        if(s1.length()+s2.length()!=s3.length())
            return false;
        vector<vector<int>>dp(s1.length()+1, vector<int>(s2.length()+1, -1));
        return solve(0, 0, 0, s1, s2, s3, dp);
    }
};