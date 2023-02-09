class Solution 
{
public:
    long long distinctNames(vector<string>& ideas) 
    {
        unordered_map<string , bool> mp;
        for(int i = 0; i < ideas.size(); i++)
        {
            mp[ideas[i]] = true;
        }
        
        vector<vector<long long>> distint(26 , vector<long long> (26,0));
        for(int i = 0 ;i < ideas.size(); i++)
        {
            string afterremovefirstchar = ideas[i].substr(1);
            int in = ideas[i][0]-'a';
            for(int j = 0; j < 26; j++) // to check after adding char a to z and check that char is present in map or not.
            {
                char y = (j+'a'); 
                string afterconcatenation = y+afterremovefirstchar;
                if(mp.count(afterconcatenation) == 0) // it means the distint word in a string then 
                {
                    distint[in][j] += 1;
                }
            }
        }
        
        long long count = 0;
        for(int i = 0; i < 26; i++)
        {
            for(int j = 0; j < 26; j++)
            {
                if(distint[i][j] > 0)
                {
                    count += distint[i][j]*distint[j][i];
                }
                    
            }
        }
        return count;
    }
};