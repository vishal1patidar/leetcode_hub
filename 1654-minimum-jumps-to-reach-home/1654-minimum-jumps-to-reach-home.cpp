class Solution {
public:
    int minimumJumps(vector<int>& forbidden, int a, int b, int x) {
        vector<vector<int>> dp(6002, vector<int> (2,0));
        if(x == 0) return 0;
        for(int &num : forbidden)
        {
            if(num == x) return -1;
            dp[num][0]++;
            dp[num][1]++;
        }
        dp[0][0] = 1;
        dp[0][1] = 1;
        queue<pair<int, int>> q;
        q.push({0,1});
        if(dp[x][1]) return -1;
        int ans = 0;
        while(!q.empty())
        {
            int s = q.size();
            while(s--)
            {
                pair<int, int> tp = q.front();
                q.pop();
                int val = tp.first;
                int ab = tp.second;
                if(val == x) return ans;
                if(ab)
                {
                    int tmp = val + a;
                    if(tmp <= 6001 && !dp[tmp][1])
                    {
                        q.push({tmp, 1});
                        dp[tmp][1]=1;
                    }
                    tmp = val - b;
                    if(tmp >= 0 && !dp[tmp][0])
                    {
                        q.push({tmp, 0});
                        dp[tmp][0]=1;
                    }
                }
                else
                {
                    int tmp = val + a;
                    if(tmp <= 6001 && !dp[tmp][1])
                    {
                        q.push({tmp, 1});
                        dp[tmp][1]=1;
                    }
                }
            }
            ans++;
        }
        return -1;
    }
};