class Solution {
public:
        vector<int> successfulPairs(vector<int>& s, vector<int>& p, long long su) {
        sort(p.begin(),p.end());  
        vector<int> result;
        for(int i=0;i<s.size();i++){  
          long long a=s[i];
          long long l=0,r=p.size()-1;
          while(l<r){              
            int mid=l+(r-l)/2;
            if(p[mid]*a >= su){
              r=mid;
            }else
                l=mid+1;
          }
          if(l==p.size()-1 && p[l]*a<su)
              l++;
          result.push_back(p.size() - l);
        }
        return result;
    }
};

