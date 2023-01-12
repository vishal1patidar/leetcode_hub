class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        int start = 0, end = n-1, mid;
        while(start <= end){
            if(start+1 == end) return min(nums[start],nums[end]);
            mid=(start+end)/2;
            if(nums[mid] > nums[end]) start=mid;   // left half is rejected
            else end = mid;   // right half is rejected
        }
        return nums[mid];
    }
};