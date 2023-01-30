class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        int n = rains.size();
        set<int> dry;
        unordered_map<int, int> wet;
        for(int i=0; i<n; i++){
            if(rains[i]) wet[rains[i]] = -1;
            else dry.insert(i);
        }
        vector<int> ans(n,1);
        for(int i=0; i<n; i++){
            if(rains[i]){
                ans[i] = -1;
                if(wet[rains[i]] != -1){
                    auto lb = dry.lower_bound(wet[rains[i]]);
                    int index = *lb;
                    if(index > i || lb == dry.end()) return {};
                    ans[index] = rains[i];
                    dry.erase(index);
                }
                wet[rains[i]] = i;
            }
        }
        return ans;
    }
};