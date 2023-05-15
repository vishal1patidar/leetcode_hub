class Solution {
public:
    bool doesValidArrayExist(vector<int>& v) {
        int xr = 0;
        for(int x : v) xr ^= x;
        return xr == 0;
    }
};