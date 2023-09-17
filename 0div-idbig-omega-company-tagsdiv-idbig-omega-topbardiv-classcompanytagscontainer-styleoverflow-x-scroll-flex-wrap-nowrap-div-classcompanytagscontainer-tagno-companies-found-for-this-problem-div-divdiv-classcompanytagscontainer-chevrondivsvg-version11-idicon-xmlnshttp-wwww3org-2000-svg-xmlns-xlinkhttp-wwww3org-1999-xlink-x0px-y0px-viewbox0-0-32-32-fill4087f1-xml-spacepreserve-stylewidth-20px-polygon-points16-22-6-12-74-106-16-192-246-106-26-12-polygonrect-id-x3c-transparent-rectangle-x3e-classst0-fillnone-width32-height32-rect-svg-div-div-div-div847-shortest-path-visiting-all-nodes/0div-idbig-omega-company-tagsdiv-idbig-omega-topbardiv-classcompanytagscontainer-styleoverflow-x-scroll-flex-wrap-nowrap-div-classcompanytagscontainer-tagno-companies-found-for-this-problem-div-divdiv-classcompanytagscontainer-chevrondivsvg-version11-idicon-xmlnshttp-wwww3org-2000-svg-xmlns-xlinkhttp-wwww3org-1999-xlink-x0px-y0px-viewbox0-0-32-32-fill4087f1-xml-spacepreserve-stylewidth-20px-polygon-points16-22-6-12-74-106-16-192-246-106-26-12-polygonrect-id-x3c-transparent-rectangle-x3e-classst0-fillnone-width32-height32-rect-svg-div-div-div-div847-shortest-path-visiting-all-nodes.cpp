class Solution {
public:
    using int3 = tuple<int, int, int>; 
    using int2 = pair<int, int>;       

    int shortestPathLength(vector<vector<int>>& graph) {
        int n = graph.size();
        set<int2> path; 
        int&& allMask = (1<<n) - 1;
        
        if (n == 1) return 0;

        queue<int3> q;
        for (int i = 0; i < n; i++) {
            int mask = 1<<i;
            q.emplace(0, i, mask);
            path.insert({i, mask});
        }

        while (!q.empty()) {
            auto [d, i, mask] = q.front();
            q.pop();
            if (mask==allMask) return d;
            
            for (int j : graph[i]) {
                int jMask= mask|(1<<j); 
                int2 edge={j, jMask};
                
                if (path.count(edge)==0) {
                    path.insert(edge);
                    q.emplace(d+1, j, jMask);
                }
            }
        }
        return -1;
    }
};

