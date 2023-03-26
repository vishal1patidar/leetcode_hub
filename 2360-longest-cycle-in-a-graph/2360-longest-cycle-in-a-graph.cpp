class Solution {
public:
    int longestCycle(vector<int>& edges) {
        int longestCycleLen = -1;
        int timeStep = 1;
        vector<int> nodeVisitedAtTime(edges.size(), 0);

        for (int currentNode = 0; currentNode < edges.size(); ++currentNode) {
            if (nodeVisitedAtTime[currentNode] > 0)
                continue;
            const int startTime = timeStep;
            int u = currentNode;
            while (u != -1 && nodeVisitedAtTime[u] == 0) {
                nodeVisitedAtTime[u] = timeStep++;
                u = edges[u];
            }
            if (u != -1 && nodeVisitedAtTime[u] >= startTime)
                longestCycleLen = max(longestCycleLen, timeStep - nodeVisitedAtTime[u]);
        }

        return longestCycleLen;
    }
};