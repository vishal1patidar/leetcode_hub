class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        int sz=0, pre;
        vector<int> dp(n);
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                    int temp=dp[j];
                if(i==0 || j==0 || matrix[i][j]=='0')
                    dp[j]=matrix[i][j]-'0';
                else
                {
                    dp[j]=min({dp[j], dp[j-1], pre})+1;
                }
                sz=max(sz, dp[j]);
                    pre=temp;
            }
        }
        return sz*sz;
    }
};