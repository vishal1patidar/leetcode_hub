class Solution {
public:
//     Objective: The goal here is to find the shortest path between the source node to every other node in the graph with an additional condition that the path between any two nodes should be color alternating.

// Intuition: We already know that we can find the shortest path between any two nodes in a graph using BFS.
// The Brute force Idea is to use BFS traversal n times so that we could find out the shortest path between all the nodes from the source node 0.
// But doing this is an overkill. We can acheive this using a single BFS traversal.

// Approach: Since we can visit all nodes in a graph using BFS traversal, we can update the shortest distance for every node when visiting that particular node. The shortest distance between source node and target node is the distance when we first visit the target node starting from source.

// Algorithm:

// First, we construct an adjacency matrix with the given red_edges and blue_edges.
// It is important for us to keep in mind the fact that there can be at most two directed edges(in the same direction)between any two nodes(a blue edge and a red edge )
// Here I am using a pair of int and int to keep track of the node index and the color of the edge respectively ( 0 for a red edge and 1 for a blue edge)
// I am keeping track of three values in the queue, the first one to denote the node index, the second one for the distance and the third one for color ( the color is -1 only for the source node)
// Use a BFS traversal and keep updating the dist only when it is not visited. Here I am updating the node value in the adjacency matrix to -1 to denote that the node has already been visited.
vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& red_edges, vector<vector<int>>& blue_edges) {
        // constructing adjacency matrix
		vector<vector<pair<int,int>>> graph(n);
        for(auto edge: red_edges)
            graph[edge[0]].emplace_back(edge[1],0); //red edges are denoted by 0 
        for(auto edge: blue_edges)
            graph[edge[0]].emplace_back(edge[1],1); // blue edges are denoted by 1
        vector<int> dist(n,-1); 
        
        queue<vector<int>> q;
        q.emplace(vector<int>{0,0,-1});
        
        while(!q.empty()) {
            auto front = q.front();
            q.pop();
            dist[front[0]] = dist[front[0]] != -1 ? dist[front[0]] : front[1];
            
            for(auto &adj : graph[front[0]]) {
				//Push the node to the queue only if the next edge color is different from the pervious edge color and also if we are visiting the edge
				//for the first time.
                if(front[2] != adj.second && adj.first!= -1) {
                    q.emplace(vector<int>{adj.first, front[1] + 1, adj.second});
					//Update the value in the adjacency matrix to -1 to denote that the node has already been visited.
                    adj.first = -1;
                }
            }
        }
        return dist;
    }
};