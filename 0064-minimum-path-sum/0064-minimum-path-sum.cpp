class Solution {
public:
    int h(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& dp){
        if(i==0 && j==0){return grid[i][j];
        }
        if(i<0 || j<0){return 1e9;}
        if(dp[i][j]!=-1){return dp[i][j];
        }
        return dp[i][j]=min(grid[i][j]+h(i-1, j, grid, dp), grid[i][j]+h(i, j-1, grid, dp));
    }
    int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size(), m=grid[0].size();
        vector<vector<int>>dp(n, vector<int>(m, -1));
        return h(n-1, m-1, grid, dp);
    }
};
