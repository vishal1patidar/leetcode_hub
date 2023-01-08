// Here is my c++ code for this problem.

// Memoization
// Complexity
// Time complexity:O(n*m)

// Space complexity:O(n*m)+O(n)

// Code
// class Solution {
// public:
//     int f(int i, int j, vector<vector<int>>& obstacleGrid, vector<vector<int>>& dp){
//         if(i==0 &&j==0 && obstacleGrid[i][j]!=1){return 1;}
//         if(i<0 || j<0){return 0;}
//         if(obstacleGrid[i][j]==1){return 0;}
//         if(dp[i][j]!=-1){return dp[i][j];}
//         return dp[i][j]=f(i-1, j, obstacleGrid, dp)+f(i, j-1, obstacleGrid, dp);
//     }
//     int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
//         int n=obstacleGrid.size(), m=obstacleGrid[0].size();
//         vector<vector<int>>dp(n, vector<int>(m, -1));
//         return f(n-1, m-1, obstacleGrid, dp);
//     }
// };
// Tabulation
// Complexity
// Time complexity:O(n*m)

// Space complexity:O(n*m)

// Code
// class Solution {
// public:
//     int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
//         int n=obstacleGrid.size(), m=obstacleGrid[0].size();
//         vector<vector<int>>dp(n, vector<int>(m, 0));
//         for(int i=0; i<n; i++){
//             for(int j=0; j<m; j++){
//                 if(obstacleGrid[i][j]==1){continue;}
//                 if(i==0 && j==0 && obstacleGrid[i][j]!=1){dp[i][j]=1;}
//                 if(i>0){dp[i][j]+=dp[i-1][j];}
//                 if(j>0){dp[i][j]+=dp[i][j-1];}
//             }
//         }
//         return dp[n-1][m-1];
//     }
// };
// Tabulation - Space Optimization
// Complexity
// Time complexity:O(n*m)

// Space complexity:O(n)

//Code
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n=obstacleGrid.size(), m=obstacleGrid[0].size();
        vector<int>dp(m, 0);
        for(int i=0; i<n; i++){
            vector<int>temp(m, 0);
            for(int j=0; j<m; j++){
                if(obstacleGrid[i][j]==1){continue;}
                if(i==0 && j==0 && obstacleGrid[i][j]!=1){temp[j]=1;}
                if(i>0){temp[j]+=dp[j];}
                if(j>0){temp[j]+=temp[j-1];}
            }
            dp=temp;
        }
        return dp[m-1];
    }
};