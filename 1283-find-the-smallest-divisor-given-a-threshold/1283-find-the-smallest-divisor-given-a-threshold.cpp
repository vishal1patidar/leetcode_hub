class Solution {
public:
    /*
    Logic : divisor can be any number from 1 to 1e6 
    1 : if this x divides and brings the sum under threshold rest lying on the right of this x on number line will also do it.
    */
    bool check(int mid , vector<int>& nums , int threshold){
        int sum = 0;
        int n = nums.size();
        for(int i = 0 ; i < n ; i++){
            int val = 0;
            if(mid >= nums[i]){
                val = 1;
            }
            else{
                val = ceil((double)nums[i]/(double)mid);
            }
            //cout<<val<<endl;
            sum += val;
        }
        //cout<<sum<<endl;
        return sum <= threshold;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int lo = 1, // bad
        hi = 1e9 , // good
        ans = 0;
        while(lo <= hi){
            int mid = lo + (hi - lo) / 2;
            //cout<<lo<<" "<<mid<<" "<<hi<<" "<<ans<<endl;
            if(check(mid , nums , threshold)){
                ans = mid;
                hi = mid - 1;
            }
            else{
                lo = mid + 1;
            }
        }
        return ans;
    }
};