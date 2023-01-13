class Solution {
public:
    void solve(int ind, string &ds, vector<string> &ans, string mapping[], string digits){
        if(ind==digits.size()){
            ans.emplace_back(ds);
            return;
        }
        string value = mapping[digits[ind]-'0'];

        for(int i=0; i<value.size(); i++){
                ds+=value[i];
                solve(ind+1, ds, ans, mapping, digits);
                ds.pop_back();
       }

    }
    vector<string> letterCombinations(string digits) {
        string ds;
        vector<string> ans;
        if(digits.size()==0)
            return ans;
        string mapping[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        solve(0, ds, ans, mapping, digits);
        return ans;      
    }
};