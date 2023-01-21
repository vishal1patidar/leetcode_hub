class Solution {
private:
    bool isPos(vector<int>& a, int l, int k){
        long long sum = 0;
        for(int i=0;i<a.size();i++){
            sum+=a[i];
            if(i >= l-1){
                if(k >= (long long)a[i]*l - sum) return true;
                sum-=a[i-l+1];
            }
        }
        return false;
    }
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int l = 1, h = nums.size(), mid;
        int ans = 1;
        while(l <= h){
            mid = l + (h-l)/2;
            if(isPos(nums, mid, k)){
                ans = max(ans, mid);
                l = mid + 1;
            } else {
                h = mid - 1;
            }
        }
        return ans;
    }
};