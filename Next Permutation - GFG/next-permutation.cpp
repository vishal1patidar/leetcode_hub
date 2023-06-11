//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
   vector<int> nextPermutation(int n, vector<int> a){
        int i = n-1;
        
        while(i > 0 && a[i-1] >= a[i])
            i--;
    
        reverse(a.begin()+i, a.end());
        
        if(i != 0) {
            int x = i-1;
            while(i < n && a[i] <= a[x])
                i++;
                
            swap(a[i], a[x]);
                
        }
        
        return a;
    }
 
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        vector<int> ans = ob.nextPermutation(N, arr);
        for(int u: ans)
            cout<<u<<" ";
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends