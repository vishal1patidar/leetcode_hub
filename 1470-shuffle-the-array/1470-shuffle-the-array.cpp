class Solution {
  public:
  vector<int> shuffle(vector<int>& nums, int n) {
    int k = 0;
    vector<int> result(2 * n);
    for (int i = 0, j = n; i < n && j < 2 * n; i++, j++) {
      result[k++] = nums[i];
      result[k++] = nums[j];
    }
    return result;
  }
};