//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++


#define ll long long
class Solution {
    public:
    ll largestSumCycle(int N, vector<int> Edge) {
        vector<ll> psum(N, -1), visited(N, -1);
        ll res = -1;
        for (ll i=0; i<N; i++) {
            if (visited[i] == -1) {
                visited[i] = i;
                psum[i] = i;
                ll j = i;
                while (Edge[j] != -1) {
                    if (visited[Edge[j]] == -1) {
                        visited[Edge[j]] = i;
                        psum[Edge[j]] = psum[j] + Edge[j];
                        j = Edge[j];
                    }
                    else {
                        if (visited[Edge[j]] == i) {
                            res = max(res, psum[j] - psum[Edge[j]] + Edge[j]);
                        }
                        break;
                    }
                }
            }
        }
        return res;
    }
};

//{ Driver Code Starts.
signed main(){
   int tc;
   cin >> tc;
   while(tc--){
      int N;
      cin >> N;
      vector<int> Edge(N);
      for(int i=0;i<N;i++){
        cin>>Edge[i];
      }
      Solution obj;
      long long ans=obj.largestSumCycle(N, Edge);
      cout<<ans<<endl;
   }
   return 0;
}
// } Driver Code Ends