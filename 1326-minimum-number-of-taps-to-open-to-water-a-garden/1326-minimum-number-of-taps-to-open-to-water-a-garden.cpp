class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        vector<int>dp(n+1,n+2);
        dp[0]=0;
        for(int i=0;i<=n;i++){
            int left=max(0,i-ranges[i]);
            for(int j=max(0,i-ranges[i]+1);j<=min(i+ranges[i],n);j++){
                dp[j]=min(dp[j],dp[left]+1);
            }
        }
         if (dp[n] == n+2) {
            return -1;
        }
        return dp[n];
    }
};