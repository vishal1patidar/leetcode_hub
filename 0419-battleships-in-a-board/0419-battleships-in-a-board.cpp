class Solution {
public:
    int countBattleships(vector<vector<char>>& grid) {
      int n=grid.size();
        int m=grid[0].size();
        int count=0;
        for(int i=0;i<n;i++)
        { for(int j=0;j<m;j++)
            {
                 if(grid[i][j]=='X')
            {  dfs(grid,i,j);
                count++;
            }
        }
            
        }
        return count;
    }
    
    void dfs(vector<vector<char>>& grid,int i,int j)
    {
        int n=grid.size();
        int m=grid[0].size();
        if(i<0 || j<0 || i>=n || j>=m || grid[i][j]!='X')
            return ;
        grid[i][j]='Y';
        dfs(grid,i+1,j);
        dfs(grid,i,j+1);
        
    }
};