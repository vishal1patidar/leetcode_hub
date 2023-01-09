class Solution {
private:
    bool dfs(int node,vector<int> &vis,vector<int> &pathVis,vector<vector<int>>& graph){
        vis[node]=1;
        pathVis[node]=1;
        //neighbours
        for(auto it:graph[node]){
            if(vis[it]==0){
                if(dfs(it,vis,pathVis,graph)==true)
                    return true;
            }
            else if(pathVis[it]==1)
                return true;
        }
        pathVis[node]=0;
        return false;
    }
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> pathVis(n,0);
        vector<int> vis(n,0);
        vector<int> ans;
        for(int i=0;i<n;i++){
            if(vis[i]==0 ){
                if(dfs(i,vis,pathVis,graph)==true)
                    continue;
            }
            if(pathVis[i]==0)
                ans.push_back(i);
        }
        
        return ans;
        
    }
};