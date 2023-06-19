//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int help(int price[],int n,int i,int p,int k,vector<vector<vector<int>>>&v){
    if(i==n){
        return v[i][p][k]=0;
    }
    if(k==0){
        return v[i][p][k]=0;
    }
    if(v[i][p][k]!=-1){
        return v[i][p][k];
    }
    if(p){
        return v[i][p][k]=max(-price[i]+help(price,n,i+1,0,k,v),0+help(price,n,i+1,1,k,v));
    }
    else{
        return v[i][p][k]=max(price[i]+help(price,n,i+1,1,k--,v),help(price,n,i+1,0,k--,v));
    }
}
    int maxProfit(int k, int n, int Arr[]) {
    // Using Recursion
    // return help(price,n,0,1,k,v);
        vector<vector<int>> ahead(2,vector<int> (k+1,0));
        vector<vector<int>> cur(2,vector<int> (k+1,0));
        for(int ind = n-1; ind>=0; ind--){
            for(int buy = 0; buy<=1; buy++){
                for(int cap=1; cap<=k; cap++){
                    
                    if(buy==0){
                        cur[buy][cap] = max(0+ahead[0][cap], 
                                    -Arr[ind] + ahead[1][cap]);
                     }
                    if(buy==1){
                        cur[buy][cap] = max(0+ahead[1][cap],
                                    Arr[ind] + ahead[0][cap-1]);
                    }
                }
            }
            ahead = cur;
        }
        return ahead[0][k];
  
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> K;
        cin >> N;
        int A[N];
        for (int i = 0; i < N; i++) cin >> A[i];

        Solution ob;
        cout << ob.maxProfit(K, N, A) << endl;
    }
    return 0;
}
// } Driver Code Ends