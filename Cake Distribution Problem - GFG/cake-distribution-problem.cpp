//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
    public:
    bool check(vector<int>& arr, int N, int K,int mid){
        int n=arr.size();
        int count=0;
        int num=0;
        for(int i=0;i<n;i++){
             num+=arr[i];
           if(num>=mid){
               count++;
            num=0;
           }
        }
        if(count<K)return false;
        return true;
    }
    int maxSweetness(vector<int>& sweetness, int N, int K) {
    // Write your code here.
    
    int l=1;
    int h=1e9;
    int ans=0;
    while(l<=h){
        int mid=(l+h)>>1;
        
        if(check(sweetness,N,K+1,mid)){
          
            ans=mid;
            l=mid+1;
        }else h=mid-1;
    }
    return ans;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> sweetness(n);
        for (int i = 0; i < n; i++) {
            cin >> sweetness[i];
        }
          Solution ob;
          int res=ob.maxSweetness(sweetness, n, k);
        cout << res << endl;
    }
}
// } Driver Code Ends