class Solution {
public:
    int specialArray(vector<int>& nums) {
	
        int count=0;
        int ans=-1;
        int x=1;
		
      for(int i=0;i<nums.size();i++) {
          for(int j=0;j<nums.size();j++){
              if(nums[j]>=x) {
                  count++;
				  } 
			  }
		  
               if(count==x) {
				  ans=x;
				  break;
				  }
			  count=0;
			  x++;
			  }
			return ans;
		}
};