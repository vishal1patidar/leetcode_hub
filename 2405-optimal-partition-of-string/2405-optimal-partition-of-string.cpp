class Solution {
public:
    int partitionString(string s) {
        int n = s.length();
        if(n==1)
            return 1;
        
        int ans = 0;
        set<char>freq; 
        freq.insert(s[0]);

        for(int i=1; i<n ;i++){
            if(freq.find(s[i]) == freq.end() )
                freq.insert(s[i]);
            
            else
            {
                ans++;
                freq.clear();
                freq.insert(s[i]);
            }
        }
        return ans+1;
    }
};