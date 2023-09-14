class Solution {
public:
    unordered_map<string, multiset<string>>   
    fly; // fly[From] is a MinHeap
    //unordered_map<string, int> indeg, outdeg;
    void build_graph(vector<vector<string>>& tickets){
        for(auto& edge: tickets){
            string From=edge[0], To=edge[1];
            fly[From].insert(To);
        }
    }
    deque<string> ans;
    void dfs(string From){
        while(!fly[From].empty()){
            auto it=fly[From].begin();
            string To=*it;
            fly[From].erase(it);
            dfs(To);
        }
        ans.push_front(From);
    }
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        build_graph(tickets);
        dfs("JFK");
        return vector<string>(ans.begin(), ans.end());
    }
};
