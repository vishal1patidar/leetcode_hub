//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    bool prime(int n){
        for(int i=2;i<n/2+1;i++){
            if(n%i==0) return false;
        }
        return true;
    }
    vector<int> primeDivision(int N){
        // code here
        vector<int> v;
        for(int i=2;i<N;i++){
            if(prime(i) && prime(N-i)){
                v.push_back(i);v.push_back(N-i);
                return v;
            }
        }
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        vector<int> ans = ob.primeDivision(N);
        cout<<ans[0]<<" "<<ans[1]<<"\n";
    }
    return 0;
}
// } Driver Code Ends