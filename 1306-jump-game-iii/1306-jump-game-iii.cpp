class Solution {
private:
bool canReach(int ind,vector<int>&vis ,vector<int> & arr){
    //BASE CASE
    if(arr[ind]==0)return true;
    if(vis[ind]==1){return false;}

    int left = false;
    int right = false;
    if(ind-arr[ind]>=0) {vis[ind]=1;left = canReach(ind-arr[ind],vis,arr);}
    if(ind+arr[ind]<arr.size()){vis[ind]=1; right = canReach(ind+arr[ind],vis,arr);}
    return left | right;

}
public:
    bool canReach(vector<int>& arr, int start) {
        vector<int> visited(arr.size(),0);
        return canReach(start,visited,arr);
    }
};