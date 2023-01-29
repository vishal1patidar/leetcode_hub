class Solution {
private:
    int get_max_index(vector<int>&a){
        int n = a.size(),ind = 0,mx =0;
        for(int j=0;j<n;j++){
            if(a[j]>mx){
                mx = a[j];
                ind = j;
            }
        }
        return ind;
    }
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n = mat.size()  , m = mat[0].size();
        int l=0 , r = n-1 ,ind;
        while(l<r){
            int mid = (l+r)/2;
            ind = get_max_index(mat[mid]);
            if((mid+1>=n or mat[mid+1][ind] < mat[mid][ind])){
                r=mid;
            }
            else{
                l=mid+1;
            }
        }
        return {l,ind};
    }
};