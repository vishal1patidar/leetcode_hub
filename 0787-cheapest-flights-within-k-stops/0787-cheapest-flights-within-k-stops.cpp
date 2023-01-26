class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int maxStop) {
        vector<vector<pair<int, int>>> edges(n, vector<pair<int, int>>());
        for (vector<int>& e: flights) {
            edges[e[0]].push_back({ e[2], e[1] });
        }
        // Created the adjacency list representation for the graph
		
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;
        vector<int> costs(n, INT_MAX);
        vector<int> stops(n, INT_MAX);
        
        pq.push({ 0, 0, src });
        costs[src] = 0;
        stops[src] = 0;
        while (!pq.empty()) {
            auto [currCost, currStop, currNode] = pq.top();
            pq.pop();
            
            if (currStop > maxStop + 1)
			//Remove if number of stops are unteneable
                continue;
            
            if (currNode == dst) {
				// If reqd node reached, exit
                return currCost;
            }
            
            for (auto& [weight, nextNode]: edges[currNode]) {
                int nextCost = currCost + weight;
                int nextStop = currStop + 1;
                if (nextCost < costs[nextNode] || nextStop < stops[nextNode]) {
					// Push in heap only if either less stops incurred or less cost incurred.
                    costs[nextNode] = nextCost;
                    stops[nextNode] = nextStop;
                    pq.push({ nextCost, nextStop, nextNode });
                }
            }
        }
        
        return -1;
        
    }
};