class Solution {
public:
    bool solve(string &s,string &p,int i,int j,int &m,int &n,vector<vector<int>> &v){
        if(i==m&&j==n)
            return true;
        if(i == m){
            for(int k = j; k < n; k++){
                if(p[k] != '*')return false;
            }
            return true;
        }
        if(j == n && i != m)
            return false;
        if(v[i][j] != -1)return v[i][j];
        bool ans = false;
        if(p[j]==s[i]){
            if(solve(s,p,i+1,j+1,m,n,v))
            ans = true;
        }
        if(p[j]== '?'){
            if(solve(s,p,i+1,j+1,m,n,v))
            ans= true;
        }
        else if(p[j] == '*'){
            if(solve(s,p,i+1,j+1,m,n,v)){
                ans = true;
            }if(solve(s,p,i+1,j,m,n,v)){
                ans = true;
            }if(solve(s,p,i,j+1,m,n,v)){
                ans = true;
            }
        }
        v[i][j] = ans;
        return ans;
    }
    
    
    bool isMatch(string s, string p) {
         int m = s.length(); 
         int n = p.length();
        vector<vector<int>> v(m,vector<int>(n,-1));
        return solve(s,p,0,0,m,n,v);
    }
};