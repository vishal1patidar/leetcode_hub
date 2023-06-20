class Solution {
public:

    int rec(int m, int n,int a, int b, vector<vector<int>> &v)
    {
        if(v[m][n]!=-1)return v[m][n];
        //cheking if the value is previously stored in DP array

        if(m==a || n==b)return 1;
        //base case
        //if the recurrsion reached the bottom or right edge then only one path is present to the final box

        v[m][n] = rec(m+1,n,a,b, v)+rec(m, n+1,a,b,v);
        //adding and storing the number of paths of right and bottom cell

        return v[m][n];
    }

    int uniquePaths(int m, int n) {
        vector<vector<int>> v(m, vector<int>(n, -1));
        return rec(0,0,m-1,n-1, v);
    }
};