class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        vector<vector<int>> g = {
            {9, 1}, {0, 2}, {1, 3}, {2, 4}, {3, 5}, {4, 6}, {5, 7}, {6, 8}, {7, 9}, {8, 0}
        };
        unordered_map<string, int> mp, vis;
        for(auto x: deadends) mp[x] = 1;
        string start = "0000";
        if(mp[start]) return -1;
        queue<string> q;
        q.push(start);
        vis[start] = 1;
        int ans = 0;
        while(!q.empty()) {
            int len = q.size();
            while(len--) {
                string u = q.front();
                q.pop();
                if(u == target) {
                    return ans;
                }
                for(int i=0; i<4; i++) {
                    for(auto c: g[u[i] - '0']) {
                        string v = u;
                        v[i] = c + '0';
                        if(!vis[v] and !mp[v]) {
                            q.push(v);
                            vis[v] = 1;
                        }
                    }
                }
            }
            ans++;
        }
        return -1;
    }
};