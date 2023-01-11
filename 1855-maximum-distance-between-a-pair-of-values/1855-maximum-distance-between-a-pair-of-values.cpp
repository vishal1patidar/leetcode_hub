class Solution {
    int helper(vector<int>&nums,int tar,int i){
        int st=i,en=nums.size()-1;
        int maxi=INT_MIN;
        while(st<=en){
            int mid=st+(en-st)/2;
            if(nums[mid]>=tar){
                maxi=max(maxi,mid-i);
                st=mid+1;
            }
            else{
                en=mid-1;
            }
        }
        return maxi;
    }
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int maxi=INT_MIN;
        for(int i=0;i<nums1.size();i++){
            maxi=max(maxi,helper(nums2,nums1[i],i));
        }
        return maxi==INT_MIN?0:maxi;
    }
};