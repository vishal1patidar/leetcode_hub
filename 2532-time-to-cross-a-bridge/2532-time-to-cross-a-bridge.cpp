class Solution {
public:
    int findCrossingTime(int n, int k, vector<vector<int>>& time) {
    priority_queue<pair<int, int>> bq_l, bq_r;
    set<pair<int, int>> wh_l, wh_r;
    int bridge_t = 0;
    for (int i = 0; i < k; ++i)
        bq_l.push({time[i][0] + time[i][2], i});
    while (n || bq_r.size() + wh_r.size()) {
      while (!wh_l.empty() && begin(wh_l)->first <= bridge_t) {
          int i = begin(wh_l)->second;
          bq_l.push({time[i][0] + time[i][2], i});
          wh_l.erase(begin(wh_l));
      }
      while (!wh_r.empty() && begin(wh_r)->first <= bridge_t) {
          int i = begin(wh_r)->second;
          bq_r.push({time[i][0] + time[i][2], i});
          wh_r.erase(begin(wh_r));
      }
      if (!bq_r.empty()) {
          int i = bq_r.top().second; bq_r.pop();
          bridge_t += time[i][2];
          wh_l.insert({bridge_t + time[i][3], i});
      }
      else if (!bq_l.empty() && n) {     
          int i = bq_l.top().second; bq_l.pop();
          --n;
          bridge_t += time[i][0];
          wh_r.insert({bridge_t + time[i][1], i});        
      }
      else
          bridge_t = min(!wh_l.empty() && n ? begin(wh_l)->first : INT_MAX,
                         !wh_r.empty() ? begin(wh_r)->first : INT_MAX);
    }
    return bridge_t;
}
};