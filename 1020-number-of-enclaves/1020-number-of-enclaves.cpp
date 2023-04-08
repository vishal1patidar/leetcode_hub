class Solution {
public:
    int n,m;
    void dfs(int i,int j,vector<vector<int>> &vis,vector<vector<int>> &grid){
        vis[i][j] = 1;
        int ro[] = {0,-1,0,1};
        int co[] = {-1,0,1,0};
        for(int ii=0;ii<4;ii++){
            int r = i + ro[ii];
            int c = j + co[ii];
            if(r>=0 && r<n && c>=0 && c<m && !vis[r][c] && grid[r][c]){
                dfs(r,c,vis,grid);
            }
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        n=grid.size(),m=grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        // first and last row
        for(int i=0;i<m;i++){
            if(grid[0][i] && !vis[0][i]){
                dfs(0,i,vis,grid);
            }
            if(grid[n-1][i] && !vis[n-1][i]){
                dfs(n-1,i,vis,grid);
            }
        }
        // first and last coloum
        for(int i=0;i<n;i++){
            if(grid[i][0] && !vis[i][0]){
                dfs(i,0,vis,grid);
            }
            if(grid[i][m-1] && !vis[i][m-1]){
                dfs(i,m-1,vis,grid);
            }
        }
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] && !vis[i][j]) ans+=1;
            }
        }
        return ans;
    }
};