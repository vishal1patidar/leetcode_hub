class Solution {
public:

	int minimumSize(vector<int>& nums, int maxOperations) {
		int i=1, j=*max_element(nums.begin(), nums.end()), ans=j;
		while(i<=j){
			int mid=i+(j-i)/2;
			int cnt=0;
			for(int k=0; k<nums.size(); k++){
				cnt+=(nums[k]/mid);
				// if(nums[k]>mid){
				//     cnt+=(nums[k]/mid);
					if(nums[k]%mid==0){cnt--;}
				// }
			}
			//cout<<cnt<<" "<<mid<<endl;
			//if(cnt==maxOperations){ans=mid;}
			if(cnt<=maxOperations){
				//cout<<ans<<endl;
				ans=mid;
				j=mid-1;
			}
			else{
				//cout<<ans<<endl;
				//ans=mid;
				i=mid+1;
			}
		}
		return ans;
	}
};