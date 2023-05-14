class Solution {
public:
        int solve(vector<int>&nums , int &mask,int n,int cnt, vector<vector<int>>&dp){
                if(((1 << n) - 1) == mask)return 0;
                int ans = 0;
                if(dp[cnt][mask] != -1)return dp[cnt][mask];
          for(int i = 0; i < n; i++){
                  if((1 << i) & mask)continue;
             for(int j = 0; j < n;j++){
                     if(i == j)continue;
                     if((1 << j) & mask)continue;
                     mask |= (1 << i);
                     mask |= (1 << j);
                 ans = max(ans , cnt * __gcd(nums[i] , nums[j]) + solve(nums, mask , n , cnt + 1 , dp));
                       mask ^= (1 << i);
                       mask ^= (1 << j);
             }
          }
                return dp[cnt][mask] =  ans;
        }
    int maxScore(vector<int>& nums) {
        int n = nums.size();
            int mask = 0;
            vector<vector<int>>dp(n+1, vector<int>(1 << n , -1));
        return solve(nums,mask,n,1,dp);
    }
};