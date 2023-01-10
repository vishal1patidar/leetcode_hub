class Solution {
public:
    vector<int> intersect(vector<int>& n1, vector<int>& n2) {
       unordered_map<int,int> mp1,mp2;
      
       vector<int> vec;
       for(int i:n1)mp1[i]++;
       
       for(int i:n2) mp2[i]++;
      for(auto i:mp1){
          int f=min(mp1[i.first],mp2[i.first]);
          for(int j=0;j<f;j++){
              vec.push_back(i.first);
          }

      
      }
       
     return vec;  }
};