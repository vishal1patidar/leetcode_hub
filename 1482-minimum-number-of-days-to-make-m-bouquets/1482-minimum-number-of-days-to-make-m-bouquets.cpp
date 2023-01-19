class Solution {
    bool good(int x, vector<int> &bd, int m, int k) {
        int cnt = 0, n = 0;
        for(int i=0; i<bd.size(); i++) {
            bd[i] <= x ? n++ : n = 0;
            if(n == k) cnt++, n = 0;
        }
        return cnt < m ? false : true;
    }
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int s = 0, e = 1e9, ans = INT_MAX;
        while(s <= e) {
            int mid = (s + e) / 2;
            if(good(mid, bloomDay, m, k)) ans = min(ans, mid), e = mid - 1;
            else s = mid + 1;
        }
        return ans == INT_MAX ? -1 : ans;
    }
};