class Solution {
public:
    bool checkOnesSegment(string s) {
        int n=s.size();
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='1')
            {
                cnt++;
            }
        }
        if(cnt==1)
        {
             return true;
        }
        
        for(int i=1;i<n-1;i++)
        {
            if(s[i]=='0' && s[i+1]=='1')
            {
                return false;
            }
        }
        return true;
    }
};