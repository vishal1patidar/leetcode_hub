//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    int getMinDiff(int arr[], int n, int k) {
        // code here
         if(n==1) return 0;//for sake of interview
        sort(arr,arr+n);//to place min and max hights at first and last
        int diff = arr[n-1]-arr[0];//this is our current diff between max and min hights
        
        int mi,ma;//min and max
        for(int i=1;i<n;i++)
        {
            if((arr[i]-k)<0) continue;
            ma = max(arr[i-1]+k,arr[n-1]-k);
            mi = min(arr[0]+k,arr[i]-k);
            
            diff = min(diff,ma-mi);
        }
        return diff;
    
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> k;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.getMinDiff(arr, n, k);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends