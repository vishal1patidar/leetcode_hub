class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int >v;
        for(auto i:nums1) v.push_back(i);//adding array to vector 
        for(auto i:nums2) v.push_back(i);// similary as above 
        sort(v.begin(),v.end());//than we sort it means arrange it in increasing order ....
        int n=v.size();// size of vector 
        
        if(n%2==0){
        return (float)(v[(n/2)-1]+v[n/2])/2;}//simple maths basically
        else
        return (float)(v[n/2]);// same AS above
    }
};