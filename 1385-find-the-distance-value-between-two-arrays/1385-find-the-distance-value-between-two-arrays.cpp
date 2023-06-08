class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        /* i-j<=d 
        i-j <=d <= j-i range; */
        sort(arr2.begin(),arr2.end());
        int ans=0;
        for (auto val: arr1){
            int low=0; int high= arr2.size()-1;
            while (low<=high){
                int mid= low+ (high-low)/2;
                if (((val-arr2[mid])>= (-1*d)) && ((val-arr2[mid])<=d))break;
                if ((val-arr2[mid])>d)low= mid+1;
                if ((val-arr2[mid]) < (-1*d))high= mid-1;
            }
            if (low<=high)continue;
            else ans++;
        }

        return ans;
    }
};