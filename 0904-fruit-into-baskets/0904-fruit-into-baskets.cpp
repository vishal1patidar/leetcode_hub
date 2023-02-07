class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        if(n<=2)
        return n;
        // can i check unique numbers in O(1)??
        // I have to tak emap here to store the values :-
int ans = INT_MIN;
        unordered_map<int,int> mp;
        int i = 0,j = 1;
        mp[fruits[0]]++;
        mp[fruits[1]]++;
        j = 2;
        while(j<n){
            // check
            mp[fruits[j]]++;
            //cout<<mp.size()<<endl;
            //cout<<i<<"  "<<j<<endl;
            while(mp.size() > 2 && i<j){
                    mp[fruits[i]]--;
                    if(mp[fruits[i]] == 0)
                    mp.erase(fruits[i]);
                    i++;
                    //cout<<mp.size()<<endl;
            }
            ans = max(ans,j-i+1);
            j++;
        }
        return ans;
    }
};