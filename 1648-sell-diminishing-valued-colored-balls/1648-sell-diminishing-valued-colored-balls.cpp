class Solution {
public:

    int mod=1000000007;    
    bool pos(vector<int>&v,int x,int t){
        int curr=0;
        for(int i=0;i<v.size();i++){
            curr+=max(0,v[i]-x+1);
            if(curr>t)
                return true;
        }
        return false;
    }
    int calculate(vector<int>&v,int x,int t){
        long long int ans=0;
        for(int i=0;i<v.size();i++){
            if(x+1>v[i])
            break;
            ans=(ans+((1ll*(v[i]+x+1)*(v[i]-x))/2)%mod)%mod;
            t-=(v[i]-x);    
        }
        ans=(ans+(1ll*t*x)%mod)%mod;
        return ans;
    }
    int maxProfit(vector<int>&v, int total) {
        sort(v.begin(),v.end(),greater<int>());
        v.push_back(0);
        int ans=0;
        int lo=0;
        int hi=v[0];
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            if(pos(v,mid,total)){
                ans=mid;
                lo=mid+1;
            }
            else{
                hi=mid-1;
            }
        }
        return calculate(v,ans,total); 
    }
};