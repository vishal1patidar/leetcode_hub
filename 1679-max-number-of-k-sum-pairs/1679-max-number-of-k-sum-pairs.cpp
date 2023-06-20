class Solution {
public:
    int maxOperations(vector<int>& num, int k) {
      sort(num.begin(), num.end());
      int ans = 0;
      int i=0, j=num.size()-1;
      while(i < j){
        if(num[i] + num[j] == k){     // found elements just increase counter
          ans++; i++; j--;
        } 
		else if(num[i] + num[j] > k) j--;  // sum is large so decrease the bigger element, i.e. jth element
        else i++;    // sum is small so increase the smaller element, i.e. ith element
      }
      return ans;
    }
};