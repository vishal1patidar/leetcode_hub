//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    // arr: input array
    // n: size of array
    //Function to find the sum of contiguous subarray with maximum sum.
    long long maxSubarraySum(int arr[], int n){
        
        // Your code here
        long long dp[n+1];
        for(int i =0; i<n;i++)
        {
            dp[i] = 0;
        }
        dp[0] = arr[0];
        long long ans = dp[0];
        for(int i =1; i<n;i++)
        {
            if(arr[i]< arr[i]+dp[i-1])
            {
                dp[i] = arr[i]+dp[i-1];
            }
            else 
            {
                dp[i] = arr[i];
            }
            if(ans < dp[i])
            {
                ans = dp[i];
            }
        }
        return ans;
        
    }
};

//{ Driver Code Starts.

int main()
{
    int t,n;
    
    cin>>t; //input testcases
    while(t--) //while testcases exist
    {
        
        cin>>n; //input size of array
        
        int a[n];
        
        for(int i=0;i<n;i++)
            cin>>a[i]; //inputting elements of array
            
        Solution ob;
        
        cout << ob.maxSubarraySum(a, n) << endl;
    }
}

// } Driver Code Ends