class Solution {
public:
    int numRescueBoats(vector<int>& p, int l) {
        sort(p.begin(),p.end());
        int i = 0;
        int j = p.size() - 1;
        int count = 0;
        while(i <= j)
        {   
            if(p[i] + p[j] <= l)
            {
                i++;
                j--;
            }
            else
                j--;   
            count++;  
        }
        return count;   
    }
};