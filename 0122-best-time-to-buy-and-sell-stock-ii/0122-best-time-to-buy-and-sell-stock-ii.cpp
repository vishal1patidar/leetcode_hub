class Solution {
public:
    int maxProfit(vector<int>& a) {
        
        int sum=0;
        for(int i=1;i<a.size();i++){
            int t=a[i]-a[i-1];
            if(t>0)
            sum+=t;
        }
        return sum;
    }
};