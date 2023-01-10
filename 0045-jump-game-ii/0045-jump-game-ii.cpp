class Solution {
public:
    int jump(vector<int>& nums) {
        
        int n=nums.size();
        if(n==1)
            return 0;
        if(nums[0]==0)
            return -1;
        int maxReach=0;
        int jump=0;
        int cur=0;
        for(int i=0;i<n;i++)
        {
            maxReach=max(maxReach, i+nums[i]);
            if(maxReach>=n-1)
                return jump+1;
            if(i==cur)
            {
                cur=maxReach;
                jump++;
            }
        }
        return -1;
        // vector<int> dp(n+1, n+1);
        // dp[0]=0;
        // for(int i=0;i<n;i++)
        // {
        //     if(dp[i]!=n+1)
        //         for(int j=i+1;j<min(n, i+nums[i]+1);j++)
        //             dp[j]=min(dp[j], 1+dp[i]);
        // }
        // return dp[n-1];
    }
};