class Solution {
public:
    int n,m;
    
    void dfs(int i,int j,vector<vector<int>> &vis,vector<vector<char>> &board){
        int ro[] = {-1,0,1,0};
        int co[] = {0,-1,0,1};
        for(int ii=0;ii<4;ii++){
            int r = i + ro[ii];
            int c = j + co[ii];
            if(r>=0 && r<n && c>=0 && c<m && !vis[r][c] && board[i][j]=='O'){
                vis[r][c] = 1;
                dfs(r,c,vis,board);
            }
        }
    }
    
    void solve(vector<vector<char>>& board) {
        n=board.size();
        m = board[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        // first and last row
        for(int j=0;j<m;j++){
            if(!vis[0][j] && board[0][j]=='O'){
                vis[0][j] = 1;
                dfs(0,j,vis,board);
            }
            if(!vis[n-1][j] && board[n-1][j]=='O'){
                vis[n-1][j] = 1;
                dfs(n-1,j,vis,board);
            }
        }
        // first and last coloum
        for(int i=0;i<n;i++){
            if(!vis[i][0] && board[i][0]=='O'){
                vis[i][0] = 1;
                dfs(i,0,vis,board);
            }
            if(!vis[i][m-1] && board[i][m-1]=='O'){
                vis[i][m-1] = 1;
                dfs(i,m-1,vis,board);
            }
        }
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && board[i][j] == 'O') board[i][j] = 'X';
            }
        }
    }
};