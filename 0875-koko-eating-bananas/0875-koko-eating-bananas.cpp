class Solution {
public:
    
    bool canEat(int n, int h, int speed, vector<int>&piles){
        int cnt=0;
        for (int i=0; i<n; i++){
            cnt+= (piles[i]/speed)+(piles[i]%speed!=0);
            if (cnt>h)return false;
        }
        return (cnt<=h);
    }
    
    int minEatingSpeed(vector<int>& piles, int h) {
        int i=1; int j= *max_element(piles.begin(),piles.end());
        int ans = j;
        while (i<=j){
            int mid= i+(j-i)/2;
            if (canEat(piles.size(),h,mid,piles)){
                ans= mid;
                j= mid-1;
            }
            else i= mid+1;
        }
        return ans;
    }
};