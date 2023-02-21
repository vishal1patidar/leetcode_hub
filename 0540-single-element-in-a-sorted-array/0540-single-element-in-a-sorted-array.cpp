class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        // support variables
        int lmt = nums.size() - 1, mid;
        // binary search
        for (int l = 0, r = lmt, prev, nxt; l <= r;) {
            // updating loop variables
            mid = (l + r) >> 1;
            prev = mid ? nums[mid - 1] : nums[mid] - 1;
            nxt = mid != lmt ? nums[mid + 1] : nums[mid] + 1;
            // checking the element pointed by mid:
            // match
            if (nums[mid] != prev && nums[mid] != nxt) return nums[mid];
            // too high
            else if (nums[mid] != (mid & 1 ? prev : nxt)) r = mid - 1;
            // too low
            else l = mid + 1;
        }
        return nums[mid];
    }
};