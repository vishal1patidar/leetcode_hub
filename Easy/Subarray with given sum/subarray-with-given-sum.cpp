//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution
{
    public:
    //Function to find a continuous sub-array which adds up to a given number.
    vector<int> subarraySum(vector<int>a, int n, long long s)
    {
        long sum=a[0];
        vector<int>v;
        
        int i=0,j=0;
        
        while(j<n)
        {
           if(sum==s)
           {
               v.push_back(i+1);
               v.push_back(j+1);
               return v;
           }
           else if(sum<s)
           {
               sum+=a[++j];
           }
           else
           {
               if(i==j)
               {
                   i++;
                   j++;
                   sum=a[i];
               }
               else
                  sum-=a[i++];
           }
        }
        v.push_back(-1);
        
        return v;
        
    }
};


//{ Driver Code Starts.

int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        long long s;
        cin>>n>>s;
        vector<int>arr(n);
        // int arr[n];
        const int mx = 1e9;
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        Solution ob;
        vector<int>res;
        res = ob.subarraySum(arr, n, s);
        
        for(int i = 0;i<res.size();i++)
            cout<<res[i]<<" ";
        cout<<endl;
        
    }
	return 0;
}
// } Driver Code Ends