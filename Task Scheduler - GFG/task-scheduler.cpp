//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int leastInterval(int N, int K, vector<char> &tasks) {
        // code here
        int freq[26]={0};
        for(auto it: tasks)
        {
            freq[it-'A']++;
        }
        int maxi = *max_element(freq,freq+26);
        int extra =0;
        for(int i =0;i<26;i++)
        {
            if(maxi==freq[i])
            extra++;
            
        }
        return max(N,(maxi + (maxi-1)*K + extra-1));
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;

        vector<char> tasks(N);
        for (int i = 0; i < N; i++) cin >> tasks[i];

        Solution obj;
        cout << obj.leastInterval(N, K, tasks) << endl;
    }
    return 0;
}
// } Driver Code Ends