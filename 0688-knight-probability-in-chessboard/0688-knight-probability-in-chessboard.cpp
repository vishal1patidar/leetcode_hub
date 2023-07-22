class Solution {
public:
    double knightProbability(int n, int k, int row, int column) {
        vector<pair<int, int>> directions = {
            {1, 2}, {1, -2}, {-1, 2}, {-1, -2},
            {2, 1}, {2, -1}, {-2, 1}, {-2, -1}
        };
        vector prevDp(n, vector<double>(n, 0));
        vector currDp(n, vector<double>(n, 0));
        prevDp[row][column] = 1;
        for (int moves = 1; moves <= k; moves++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    currDp[i][j] = 0;
                    for (const auto& direction : directions) {
                        int prevI = i - direction.first;
                        int prevJ = j - direction.second;

                        if (prevI >= 0 && prevI < n && prevJ >= 0 && prevJ < n) {
                            currDp[i][j] += prevDp[prevI][prevJ] / 8;
                        }
                    }
                }
            }
            prevDp.swap(currDp);
        }
        double totalProbability = 0;
        for (const auto& row : prevDp) {
            for (const auto& cell : row) {
                totalProbability += cell;
            }
        }
        return totalProbability;
    }
};