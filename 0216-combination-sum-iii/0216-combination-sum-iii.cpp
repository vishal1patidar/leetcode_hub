class Solution {
public:
    void generateCombos(int idx, int k, int n, vector<int>& temp, vector<vector<int>>& sol){
        if(!k||!n){
            if(!k&&!n) sol.push_back(temp);
            return;
        }

        for(int i=idx;i<=9;i++){
            if(n<i) return;
            
            temp.push_back(i);
            generateCombos(i+1, k-1, n-i, temp, sol);
            temp.pop_back();
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> temp;
        vector<vector<int>> sol;

        generateCombos(1, k, n, temp, sol);
        return sol;
    }
};