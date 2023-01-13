class Solution {
public:
    void parentheses(int open, int closed, string &s, vector<string> &ans){
        if(open == 0 && closed == 0){
            ans.emplace_back(s);
            return;
        }
        if(open>0){
            s+="(";
            parentheses(open-1, closed, s, ans);
            s.pop_back();
        }
        if(closed>0 && closed>open){
            s+=")";
            parentheses(open, closed-1, s, ans);
            s.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string s="(";
        int open = n-1;
        int closed = n;
        parentheses(open, closed, s, ans); 
        return ans;
    }
};