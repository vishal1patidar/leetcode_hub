class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        set<int> flag_i;
        set<int> flag_j;
        for(int i=0;i<matrix.size();i++) {
            for(int j=0;j<matrix[0].size();j++) {
                if(matrix[i][j] == 0) {
                    flag_i.insert(i);
                    flag_j.insert(j);
                }
            }
        }
        for(int i=0;i<matrix.size();i++) {
            for(int j=0;j<matrix[0].size();j++) {
                if(flag_i.find(i) != flag_i.end() || flag_j.find(j) != flag_j.end()) {
                   matrix[i][j] = 0;
                }
            }
        }
    }
};