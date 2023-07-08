class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        
    if(k==1) return 0;
    vector<long long> ans;
    for(int i=1;i<weights.size();i++)
    ans.push_back(weights[i-1]+weights[i]);
    sort (ans.begin(),ans.end()) ;
    long long l=0,r=0;
    for(int i=0;i+1<k;i++)
        l+=ans[i],r+=ans[ans.size()-1-i];
    return (r-l);
        
    }
};