class Solution {
public:
    bool dfs(int i,int col,vector<int>&color,vector<vector<int>>&adj,int n){
        color[i]=col;
        for(auto it:adj[i]){
            if(color[it]==-1){
                if(dfs(it,!col,color,adj,n)==false) return false;
            }
            else if(color[it]==col) return false;
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& adj) {
        int n=adj.size();
        vector<int>color(n,-1);
	    for(int i=0;i<n;i++){
	        if(color[i]==-1){
	            if(dfs(i,0,color,adj,n)==false) return false;
	        }
	    }
	    return true;
    }
};