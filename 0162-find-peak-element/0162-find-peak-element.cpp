class Solution {
public:
    int sol(vector<int>& nums, int l, int h)
    {
        while(l<=h)
        {
            int m=(l+h)/2;
            if(m==0 && nums[m]>nums[m+1])
            return m;
            if(m==nums.size()-1 && nums[nums.size()-1]>nums[nums.size()-2])
            return m;
            if(nums[m]>nums[m+1] && nums[m]>nums[m-1])
            return m;
            if(nums[m+1]> nums[m])
            l=m+1;
            else 
            h=m-1;
        }
        return l;
    }
    int findPeakElement(vector<int>& nums) {
        int n=nums.size();
        if(n==1)
        return 0;

       return sol(nums, 0, n-1);
    }
};