class Solution {
public:
    int findLatestStep(vector<int>& arr, int m) {
        int n = arr.size();
        if (m == n) return n;
        vector<int> len(n + 2, 0);
        vector<int> cnt(n + 1, 0);
        int res = -1;
        for (int i = 0; i < n; ++i) {
            int a = arr[i];
            int l = len[a - 1], r = len[a + 1];
            int sum = l + r + 1;
            len[a - l] = len[a + r] = sum;
            cnt[l]--;
            cnt[r]--;
            cnt[sum]++;
            if (cnt[m] > 0) res = i + 1;
        }
        return res;
    }
};