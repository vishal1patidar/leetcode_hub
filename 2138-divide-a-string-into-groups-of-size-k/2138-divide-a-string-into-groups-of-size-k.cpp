class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string>v;  // create an empty vector to store the divided strings
        if(s.size()%k!=0){  // check if the string cannot be divided evenly into k-sized groups
            int next = ceil(float(s.size())/float(k));  // calculate the number of groups needed
            int rem = (next*k) - s.size();  // calculate the number of fill characters needed
            for(int i =0;i<rem;i++){  // add the fill characters to the end of the string
                s+=fill;
            }
        }
        int temp = 0;  // initialize a counter variable to keep track of the group size
        string str = "";  // initialize an empty string to store each group
        for(int i =0;i<s.size();){  // loop over the characters in the string
            str = "";  // reset the string for each new group
            while(temp != k){  // loop until the group size reaches k
               str+=s[i];  // add the current character to the group string
               i++;  // move to the next character in the string
               temp++;  // increment the group size counter
           }
            v.push_back(str);  // add the completed group string to the vector
            temp = 0;  // reset the group size counter for the next group
        }
        return v;  // return the vector containing all the divided strings
    }
};
