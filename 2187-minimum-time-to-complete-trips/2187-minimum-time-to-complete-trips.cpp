class Solution {
public:
    long long minimumTime(vector<int>& time, int x) {
        long long int mx = LONG_LONG_MAX/time.size(), mn = 1,mid,ans,k;
        // for(auto &i: time){
        //     mx += i;
        //     mn = min(mn,(long long int)i);
        // }
        while(mn<=mx){
            mid = (mx-mn)/2+mn;
            k = 0;
            for(auto &i: time){
                k += (mid/i);
            }
            if(k>=x){
                ans = mid;
                mx = mid-1;
            }else{
                mn = mid+1;
            }
        }
        return ans;
    }
};