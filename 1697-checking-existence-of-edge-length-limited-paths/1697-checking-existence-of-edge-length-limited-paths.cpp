class Solution {
public:
// find function which is used to find parent of a node
    int find(int node, vector<int>& parent)
    {
        // if node is parent of itself return here
        if(node == parent[node])
            return node;
        
        // else go on in finding actual parent
        return parent[node] = find(parent[node], parent);
    }
    
    // union funtion to merge parents of two nodes
    void Union(int node0, int node1, vector<int>& parent)
    {
        int par0 = find(node0, parent); // find parent of node zero
        int par1 = find(node1, parent); // find parent of node one
        
        // if values of parents of node zero and one are equal 
        // then we will return true from here
        if(par0 == par1)
            return;
        
        // make parent of one anothoer (parent[par1] = par0, also valid)
        parent[par0] = par1;
    }

    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edges, vector<vector<int>>& queries) {
        int q = queries.size(); // defining size of queries array
        int sz = edges.size(); // defining size of edges array 

        // Intiliaze parent array, which will take care of parent of every node
        vector<int> parent(n, 0); 

        // intially make parent of everyone itself
        for(int i = 0; i < n; i++) parent[i] = i;

        // sort edges on the basis of distance weight
        sort(edges.begin(), edges.end(), [&](vector<int>& edge1, vector<int>& edge2){
            return edge1[2] < edge2[2];
        });

        // keep track of original indices
        for(int i = 0; i < q; i++) queries[i].push_back(i);
        
        // sort queries on the basis of weight
        sort(queries.begin(), queries.end(), [&](vector<int>& query1,vector<int>& query2) {
            
            return query1[2] < query2[2];
        });

        // declare answer array of size q, intially everything false
        vector<bool> ans(q, false);
        int edgeMoment = 0; // pointer to move in edges array

        // now, for each query we will calculate answer
        for(int eachQuery = 0; eachQuery < q; eachQuery++) {
            int currQueryWeight = queries[eachQuery][2]; // currentWeight in queries
            
            // move in edges till edge distane weight less than currQueryWeight 
            // and map parents
            while(edgeMoment < sz && edges[edgeMoment][2] < currQueryWeight)
            Union(edges[edgeMoment][0], edges[edgeMoment][1], parent), edgeMoment++;

            // if for this currQueryWeight, queries nodes found in same group,
            // put answer true
            if(find(queries[eachQuery][0], parent) == 
            find(queries[eachQuery][1], parent))  {

                ans[queries[eachQuery][3]] = true;
            }
        }
        
        // finally, return ans
        return ans;
    }
};