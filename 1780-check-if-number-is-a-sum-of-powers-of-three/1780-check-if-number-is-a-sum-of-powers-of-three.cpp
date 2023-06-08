class Solution {
public:
    bool checkPowersOfThree(int n) {
        int sum {};
        int max = floor(log(n)/log(3));
        int increase {};
        for(int i {max}; i >=0; i--){
            increase = pow(3,i);
            if(sum + increase > n){
                continue;
            }
            sum += increase;
            if(sum==n){
                return true;
            }
            
        }
        return false;
    }
};