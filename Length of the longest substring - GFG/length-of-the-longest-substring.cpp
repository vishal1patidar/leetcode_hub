//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
     int longestUniqueSubsttr(string s){
    
        vector<int> mp(256, -1);
        int n = s.size();
        int l = 0;
        int r = 0;
        int len = 0;
        
        while(r < n) {
            if(mp[s[r]] != -1) {
                l = max(l, (mp[s[r]] + 1));
            }
            
            mp[s[r]] = r;
            len = max(len, r - l + 1);
            r++;
            
        }
        return len;
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string str;
		cin>>str;
		Solution ob;
		cout<<ob.longestUniqueSubsttr(str)<<endl;
	}
	return 0;
}
// } Driver Code Ends