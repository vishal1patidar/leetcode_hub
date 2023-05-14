//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int matrixMultiplication(int n, int arr[]){
        // code here
        vector<vector<int>> dp(n,vector<int> (n,0));
        int i=0,j=1;
        while(j<n&&i<n){
            dp[i][j]=0;
            i++;
            j++;
        }
        for(int gap=2;gap<n;gap++){
            int i = 0, j = gap;
            while(j<n&&i<n){
                int store=INT_MAX;
                for(int k=i+1;k<j;k++){
                  int val = dp[i][k] + dp[k][j];
                  val+=arr[i]*arr[k]*arr[j];
                  store=min(store,val);
                }
                dp[i][j]=store;
                i++;
                j++;
            }
        }
        return dp[0][n-1];
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.matrixMultiplication(N, arr)<<endl;
    }
    return 0;
}
// } Driver Code Ends