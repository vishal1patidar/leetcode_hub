class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        bool ans=false;
        for(int i=0;i<arr.size();i++)
        {
            for(int j=0;j<arr.size();j++)
            {
                if(i!=j  && arr[i]==2*arr[j])
                {
                    ans=true;
                }
            }
            
        }

        return ans;
    }
};