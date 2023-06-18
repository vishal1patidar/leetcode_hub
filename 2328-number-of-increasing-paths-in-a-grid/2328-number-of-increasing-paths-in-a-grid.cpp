class Solution {
public:
    int countPaths(vector<vector<int>>& grid) {
        vector<array<int, 3> > h;
        vector<vector<int> > dp;
        int n = grid.size();
        int m = grid[0].size();
        dp.resize(n);
        for (int i = 0; i < n; i++) {
            dp[i].resize(m);
        }
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                h.push_back({grid[i][j], i, j});
        sort(h.begin(), h.end());
        int mod = 1e9 + 7;
        int ans = 0;
        for (auto v : h) {
            int i = v[1], j = v[2];
            int mv[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
            dp[i][j] = 1;
            for (int k = 0; k < 4; k++) {
                int ei = i + mv[k][0], ej = j + mv[k][1];
                if (ei < 0 || ej < 0 || ei >= n || ej >= m) continue;
                if (grid[ei][ej] >= grid[i][j]) continue;
                dp[i][j] = (dp[i][j] + dp[ei][ej]) % mod;
            }
            ans = (ans + dp[i][j]) % mod;
        }
        return ans;
    }
};