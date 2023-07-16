class Solution {
public:
    vector<int> smallestSufficientTeam(vector<string>& req_skills,
        vector<vector<string>>& people) {
        int skills = req_skills.size();
        int no_people = people.size();
        int possible = pow(2, skills);
        unordered_map<string, int> mapping;
        for(int i = 0; i<skills; i++){
            mapping[req_skills[i]] = i;
        }
        unordered_map<int, vector<int>> dp;
        dp.reserve(1 << skills);
        dp[0] = {};

        for(int i = 0; i<no_people; i++){
            int size = people[i].size();
            int val = 0;
            for(int j = 0; j<size; j++){
                int index = mapping[people[i][j]];
                val = val | (1<<index);
            }
            for (auto it = dp.begin(); it != dp.end(); ++it) {
                int comb = it->first | val;
                if (dp.find(comb) == dp.end() || 
                    dp[comb].size() > 1 + dp[it->first].size()){
                        dp[comb] = it->second;
                        dp[comb].push_back(i);
                }
            }

        }
        return dp[possible-1];
    }
};