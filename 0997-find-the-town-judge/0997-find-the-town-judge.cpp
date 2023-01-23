// Make two arrays :-
// a. arr1 for keeping count of who trusts ith member
// b. arr2 for keeping count of all the people ith member trusts

// The judge must trust noone i.e. arr1[i] == 0

// All members must trust judge i.e. arr2[i] == n-1


class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int>arr1(n+1);
        vector<int>arr2(n+1);
        for(int i = 0;i < trust.size();i++){
            arr1[trust[i][0]]++;   
            arr2[trust[i][1]]++;
        }
        for(int i = 1;i <= n;i++){
            if(arr1[i] == 0 && arr2[i] == n-1)return i;
        }
        return -1;
    }
};