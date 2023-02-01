class Solution {
public:
    // get number of ugly nums less than mid
    long long numLess(long long a, long long b, long long c, long long x){
        long long ans = 0;
        long long ab = a*b/__gcd(a,b);
        long long ac = a*c/__gcd(a,c);
        long long bc = b*c/__gcd(b,c);
        long long abc = ab*c/__gcd(ab,c);
        
        ans += x/a + x/b + x/c;
        ans -= x/ab + x/ac + x/bc;
        ans += x/abc;
        return ans;
    }
    
    int nthUglyNumber(int n, int a, int b, int c) {
        if(a==1 || b==1 || c==1) return n;
        long long low=0, high=2e9;
        while(low<high){
            long long mid = (low+high)/2;
            if(numLess(a,b,c,mid) >= n) high = mid;
            else low = mid+1;
        }
        return low;
    }
};