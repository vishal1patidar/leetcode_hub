class Solution {
public:
    int hIndex(vector<int>& c) {
        ios::sync_with_stdio(0);
        cin.tie(NULL);
        
        int n = c.size();
        int low = 0, high = n - 1, mid;
        while(low <= high) {
            //To Avoid overflow Condition
            int mid = low + (high - low) / 2;
            if(c[mid] == (n - mid))
                return c[mid];
            
            else if(c[mid] > (n - mid))
                high = mid - 1;
            else
                low = mid + 1;
        }
        return n - low;
    }
};