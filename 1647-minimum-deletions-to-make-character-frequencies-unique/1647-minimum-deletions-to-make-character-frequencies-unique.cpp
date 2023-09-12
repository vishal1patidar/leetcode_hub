
class Solution {
public:
    int minDeletions(string s) {
        vector<int> freq(26, 0);
        for(char c: s)
            freq[c-'a']++;
        sort(freq.begin(), freq.end(), greater());
        int upper=freq[0];
        int ans=0;
        int i, f;
        for(i=1; i<26 && upper>=1; i++){
            f=freq[i];
            int del=f+1-upper;
            if (del<0) upper=f;
            else{
                ans+=del;
                upper--;
            }
        }
        while(f>0 && i<26){
            f=freq[i];
            ans+=f;
            i++;
        }
        return ans;
    }
};