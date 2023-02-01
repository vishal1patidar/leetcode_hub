class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        int n = str1.size();
        int n1 = str2.size();
        string ans="";
        for(int i=1;i<=n;i++)
        {
            string tmp = str1.substr(0,i);
            int flg=0;
            int cnt1=0,cnt2=0;
            for(int j=0;j<n && j+tmp.size()<=n;j+=tmp.size())
            {
                string tmp2 = str1.substr(j,tmp.size());
                cnt1++;
                if(tmp!=tmp2)
                {
                    flg=1;
                    break;
                }
            }
            for(int j=0;j<n1 && j+tmp.size()<=n1;j+=tmp.size())
            {
                string tmp2 = str2.substr(j,tmp.size());
                cnt2++;
                if(tmp!=tmp2)
                {
                    flg=1;
                    break;
                }
            }
            int ch = tmp.size();
            if(cnt1!=ceil((double)n/ch) || cnt2!=ceil((double)n1/ch))
            flg=1;
            if(!flg)
            {
                if(ans.size()<tmp.size())
                {
                    ans = tmp;
                }
            }
        }
        return ans;
    }
};