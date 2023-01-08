class disjointset{
    public:
    vector<int>par;
    disjointset(int n){
        par.resize(n+1);
        for(int i=0; i<=n; i++){
            par[i]=i;
        }
    }
    int findp(int u){
        if(par[u]==u){return u;}
        return par[u]=findp(par[u]);
    }
    void un(int u, int v){
        par[findp(u)]=par[findp(v)];
    }
};
class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        disjointset d(n);
        int cnt=0, cnt1=0;
        for(auto it: connections){
            if(d.findp(it[0])!=d.findp(it[1])){
                d.un(it[0], it[1]);
            }
            else{
                cnt++;
            }
        }
        for(int i=0; i<n; i++){
            if(d.findp(i)==i){cnt1++;}
        }
        if(cnt1-1<=cnt){return cnt1-1;}
        return -1;
    }
};