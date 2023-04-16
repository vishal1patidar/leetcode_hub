class Solution {
public:
    int dp[51][2] = {}; // dp optimization to not recalculate values
    int mp[51] = {}; // count how many times a node is used in trips
    typedef array<int, 2> ai;
    void countPaths(vector<vector<int>>& adj, int x, int y){
        queue<ai> q;
        q.push({x, -1});
        int vis[51] = {};
        int last[51] = {}; // so we can efficiently backtrack the path from node a to node b
        while(!q.empty()){
            auto [t, p] = q.front();
            q.pop();
            if(vis[t]++) continue;
            last[t] = p;
            if(t == y){
                while(t != -1){
                    mp[t]++; 
                    t = last[t];
                } 
                return;
            }
            for(auto i : adj[t]) q.push({i, t});
        }
    }
    int dfs(vector<vector<int>>& adj, int pos, vector<int>& price, vector<vector<int>>& trips, bool canTake, int last){
        if(dp[pos][canTake] != -1) return dp[pos][canTake];
        int ans = price[pos] * mp[pos];
        int res1 = 0, res2 = 0;
        for(auto i : adj[pos]) if(i != last) res1 += dfs(adj, i, price, trips, true, pos);
        if(canTake){
            for(auto i : adj[pos]) if(i != last) res2 += dfs(adj, i, price, trips, false, pos);
            ans = min(ans+res1, ans/2 + res2);
        }
        else ans = ans+res1;
        return dp[pos][canTake] = ans;
    }
    int minimumTotalPrice(int n, vector<vector<int>>& edges, vector<int>& price, vector<vector<int>>& trips) {
        vector<vector<int>> adj(n);
        memset(dp, -1, sizeof dp);
        for(auto&i:edges){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        for(auto& i : trips) countPaths(adj, i[0], i[1]);
        return dfs(adj, 0, price, trips, true, -1);
    }
};