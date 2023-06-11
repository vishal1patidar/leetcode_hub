//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
public:
    // Function to determine if graph can be coloured with at most M colours such
    // that no two adjacent vertices of graph are coloured with same colour.
   int colour[20] ;
    bool result = false ; 
    void helper(bool graph[101][101],int m,int n,int i){
        if(i==n){
            result = true ; 
            return ; 
        }
        if(!result){
            vector<int> available(m+1,1) ; 
            for(int j=0 ; j<n ; j++){
                if(graph[i][j] && colour[j])   available[colour[j]]=0 ; 
            }
            for(int j=1 ; j<=m ; j++){
                if(available[j]){
                    colour[i]=j ; 
                    helper(graph,m,n,i+1) ; 
                    colour[i]=0 ; 
                    if(result)  return ;
                }
            }
        }
    }
    bool graphColoring(bool graph[101][101], int m, int n) {
        for(int i=0 ; i<n ; i++)    colour[i]=0 ; 
        helper(graph,m,n,0) ; 
        return result ;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, e;
        cin >> n >> m >> e;
        int i;
        bool graph[101][101];
        for (i = 0; i < n; i++) {
            memset(graph[i], 0, sizeof(graph[i]));
        }
        for (i = 0; i < e; i++) {
            int a, b;
            cin >> a >> b;
            graph[a - 1][b - 1] = 1;
            graph[b - 1][a - 1] = 1;
        }
        Solution ob;
        cout << ob.graphColoring(graph, m, n) << endl;
    }
    return 0;
}

// } Driver Code Ends