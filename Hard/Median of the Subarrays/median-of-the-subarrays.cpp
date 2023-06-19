//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution {
  public:
    long long Median(int n, vector<int> &A, int m)
    {
        vector<int> v((2 * n) + 1);
        long long a = n, b = 0, c = 0;
        v[a]++;
        int x;
        for (int i = 0; i < n; i++)
        {
            x = -1;
            if (A[i] >= m)
            {
                x = 1;
            }
            if (x == -1)
            {
                b -= v[a + x];
            }
            else
            {
                b += v[a];
            }
            a += x;
            c += b;
            v[a]++;
        }
        // for(int i = 0; i < v.size(); i++)
        // {
        //     cout << v[i] << " ";
        // }
        // cout << endl;
        return c;
    }
    long long countSubarray(int N,vector<int> A,int M) 
    {
        return (Median(N, A, M) - Median(N, A, M + 1));
    }


};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M;
        cin>>N>>M;
        vector<int> A(N);
        for(int i=0;i<N;i++){
            cin>>A[i];
        }
        Solution obj;
        auto ans = obj.countSubarray(N,A,M);
        cout<<ans<<endl;
    }
}  
// } Driver Code Ends