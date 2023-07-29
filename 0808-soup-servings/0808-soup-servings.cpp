class Solution {
public:
    vector<vector<double>>Dp;
    double fun(int a , int b)
    {
        if(a <= 0 && b <= 0)
            return 0.5;
        else if(a <= 0 && b > 0)
            return 1;
        else if(b <= 0 && a > 0)
            return 0;
        else if(Dp[a][b] != -1)
            return Dp[a][b];
        double ans = 0;
        ans += 0.25 * fun(a - 100 , b);
        ans += 0.25 * fun(a - 75 , b - 25);
        ans += 0.25 * fun(a - 50 , b - 50);
        ans += 0.25 * fun(a - 25 , b - 75);
        return Dp[a][b] = ans;

    }
    double soupServings(int n) {
        int a = n ;
        int b = n;
        if(n >= 5000)
            return 1.0;
        Dp.resize(n+1,vector<double>(n + 1 , -1.000000));
        double x = fun(a,b);
        return x;
    }
};
