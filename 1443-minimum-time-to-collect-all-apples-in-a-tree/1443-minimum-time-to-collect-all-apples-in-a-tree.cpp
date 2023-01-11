class Solution {
public:
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
       // creating adjacency list
        vector<vector<int>> a(n);
        for (auto& x : edges) {
            a[x[0]].push_back(x[1]);
            a[x[1]].push_back(x[0]);
        }

        return dfs(-1, 0, a, hasApple);
    }

    int dfs(int prev, int curr, vector<vector<int>>& a, vector<bool>& hasApple) {
        int ans = 0;
        for (auto x : a[curr]) {
            if (x != prev) {
                int res = dfs(curr, x, a, hasApple);
                if (res > 0 || hasApple[x]) {
                    ans += (res + 2);
                }
            }
        }
        return ans;
    }
};