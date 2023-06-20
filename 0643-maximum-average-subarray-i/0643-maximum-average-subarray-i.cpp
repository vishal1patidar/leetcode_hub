class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double sum = 0, maxSum = INT_MIN;
        
        for (int i = 0; i < nums.size(); i++) {
            if (i < k) {
                sum += nums[i];
                continue;
            }
            maxSum = max(sum, maxSum);
            sum += nums[i] - nums[i-k];
        }

        maxSum = max(sum, maxSum);
        return maxSum / (double) k;
    }
};