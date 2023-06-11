//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
public:
   int n;
vector<int> dp;
    int f(int idx, int k, vector<int> &nums) {
        // if(idx==n) return 0; // includes answer of last row also 
        int ans = INT_MAX, K = k;
        if(dp[idx]!=-1) return dp[idx];
        
        for(int i=idx; i<n; i++) {
            k-=nums[i];
            if(k>=0) {
                if(i==n-1) return 0;
                ans = min(ans, f(i+1, K, nums) + k*k);
            }
            else break;
            k--;
        }
        return dp[idx] = ans;
    }
    int solveWordWrap(vector<int>nums, int k) 
    {
        n = nums.size();
        dp.resize(n, -1);
        return f(0, k, nums);
    }  
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, k;
        cin >> n;
        vector<int>nums(n);
        for (int i = 0; i < n; i++)cin >> nums[i];
        cin >> k;
        Solution obj;
        cout << obj.solveWordWrap(nums, k) << endl;
	}
	return 0;
}
// } Driver Code Ends