class Solution {
public:
    int solve(vector<int> &prices, int fee, int index, bool buy){
        if(index == prices.size()) return 0;

        int profit = 0;
        if(buy){
            int choose = -prices[index] + solve(prices, fee, index+1, 0);
            int skip = 0 + solve(prices, fee, index+1, 1);

            profit = max(choose, skip);
        }
        else{
            int choose = (prices[index] - fee) + solve(prices, fee, index+1, 1);
            int skip = 0 + solve(prices, fee, index+1, 0);

            profit = max(choose, skip);
        }

        return profit;
    }

    int solveMem(vector<int> &prices, int fee, int index, bool buy, vector<vector<int>> &dp){
        if(index == prices.size()) return 0;

        if(dp[index][buy] != -1){
            return dp[index][buy];
        }

        int profit = 0;
        if(buy){
            int choose = -prices[index] + solveMem(prices, fee, index+1, 0, dp);
            int skip = 0 + solveMem(prices, fee, index+1, 1, dp);

            profit = max(choose, skip);
        }
        else{
            int choose = (prices[index] - fee) + solveMem(prices, fee, index+1, 1, dp);
            int skip = 0 + solveMem(prices, fee, index+1, 0, dp);

            profit = max(choose, skip);
        }

        return dp[index][buy] = profit;
    }

    int solveTab(vector<int> &prices, int fee){
        int n = prices.size();
        vector<vector<int>> dp(n+1, vector<int>(2, 0));

        for(int index = n-1; index >= 0; index--){
            for(int buy = 0; buy <= 1; buy++){

                int profit = 0;
                if(buy){
                    int choose = -prices[index] + dp[index+1][0];
                    int skip = 0 + dp[index+1][1];

                    profit = max(choose, skip);
                }
                else{
                    int choose = (prices[index] - fee) + dp[index+1][1];
                    int skip = 0 + dp[index+1][0];

                    profit = max(choose, skip);
                }

                dp[index][buy] = profit;

            }
        }

        return dp[0][1];
    }

    int solveSO(vector<int> &prices, int fee){
        int n = prices.size();
        vector<int> curr(2, 0);
        vector<int> next(2, 0);

        for(int index = n-1; index >= 0; index--){
            for(int buy = 0; buy <= 1; buy++){

                int profit = 0;
                if(buy){
                    int choose = -prices[index] + next[0];
                    int skip = 0 + next[1];

                    profit = max(choose, skip);
                }
                else{
                    int choose = (prices[index] - fee) + next[1];
                    int skip = 0 + next[0];

                    profit = max(choose, skip);
                }

                curr[buy] = profit;

            }

            next = curr;
        }

        return curr[1];
    }

    int maxProfit(vector<int>& prices, int fee) {
        // int n = prices.size();
        // vector<vector<int>> dp(n, vector<int>(2, -1));

        // return solveMem(prices, fee, 0, 1, dp);

        return solveSO(prices, fee);
    }
};