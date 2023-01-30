class Solution {
public:
int tribonacci(int n) {
int A[n+1];
if(n == 0 || n ==1) return n;
if(n==2) return 1;
A[0] = 0;
A[1] = 1;
A[2] = 1;
for(int i = 3;i<=n;i++){
A[i] = A[i-1]+A[i-2]+A[i-3];
}
return A[n];
}
};