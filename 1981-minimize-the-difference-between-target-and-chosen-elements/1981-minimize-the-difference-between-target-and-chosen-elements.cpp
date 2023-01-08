class Solution {
public:
    int dp[4901][71];
    int minimizeTheDifference(vector<vector<int>>& mat, int target) 
    {
        //int fun(vector<vector<int>>&mat,int &target,int sum,int row);
        memset(dp,-1,sizeof(dp));
        int row=0;
        int sum=0;
        return fun(mat,target,sum,row);
    }
    int fun(vector<vector<int>>&mat,int &target,int sum,int row)
    {
        if(row >= mat.size())
        {
           return abs(target-sum);	
        }

        if(dp[sum][row]!=-1)
            return dp[sum][row];

        int ans=INT_MAX;   //final ans that we will return   //ans-->9
        for(int i=0;i<mat[row].size();i++)
        {
           ans=min(ans,fun(mat,target,sum+mat[row][i],row+1));
           if(ans==0)
           {
              return dp[sum][row]=ans;
           }
        }
        return dp[sum][row]=ans;
    }
};