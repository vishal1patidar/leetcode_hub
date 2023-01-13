class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int ans=0;
        for(int i=0; i<nums.size(); i++){
            for(int j=i+1; j<nums.size(); j++){
                int num=nums[i]+nums[j];
                int st=j+1, en=nums.size()-1;
                while(st<=en){
                    int mid=st+(en-st)/2;
                    if(nums[mid]<num){
                        st=mid+1;
                    }
                    else{en=mid-1;}
                }
                //cout<<st<<endl;
                ans+=en-j;
            }
        }
        return ans;
    }
};