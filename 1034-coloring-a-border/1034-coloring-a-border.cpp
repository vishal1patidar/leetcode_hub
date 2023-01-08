class Solution {
    void dfs(int i, int j, vector<vector<int>>& grid, int orgc, int c, vector<vector<int>> &temp) {
        if(i < 0 || i == grid.size() || j < 0 || j == grid[0].size() || grid[i][j] != orgc || grid[i][j] == c) return;
        grid[i][j] = c;
        
        dfs(i + 1, j, grid, orgc, c, temp);
        dfs(i - 1, j, grid, orgc, c, temp);
        dfs(i, j + 1, grid, orgc, c, temp);
        dfs(i, j - 1, grid, orgc, c, temp);
        
        if(i - 1 >= 0 && i + 1 < grid.size() && j - 1 >= 0 && j + 1 < grid[0].size()) {
            if(temp[i - 1][j] == orgc && temp[i + 1][j] == orgc && temp[i][j - 1] == orgc && temp[i][j + 1] == orgc) grid[i][j] = orgc;
        }
    }
    
public:
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int i, int j, int c) {
        vector<vector<int>> temp = grid;
        dfs(i, j, grid, grid[i][j], c, temp);
        return grid;
    }
};