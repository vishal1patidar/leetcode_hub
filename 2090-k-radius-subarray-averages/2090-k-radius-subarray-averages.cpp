class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n = nums.size();
        int windowSize = 2 * k + 1;
        
        long long windowSum = 0;
        vector<int> result(n, -1);

        if (n < windowSize) {
            return result;
        }

        for (int i = 0; i < n; ++i) {
            windowSum += nums[i]; // Add nums[i] to the window sum

            if (i - windowSize >= 0) {
                windowSum -= nums[i - windowSize]; // Remove nums[i - windowSize] from the window sum
            }

            if (i >= windowSize - 1) {
                result[i - k] = windowSum / windowSize; // Calculate and store the average in the result
            }
        }

        return result;
    }
};