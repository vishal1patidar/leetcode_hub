class Solution {
public:
    string decodeString(string s) {
        stack<string> st;
        for(auto ch: s){
            if(ch==']'){
                string stringtorepeat="";
                while(!st.empty()&& st.top()!="["){
                    string top=st.top();
                    stringtorepeat+=top;
                    st.pop();
                }
                st.pop();//st.top has '[' this one the top so pop
                //now we will take number of time we want to repeat 
                string num="";
                while(!st.empty() && isdigit(st.top()[0])){
                    string top=st.top();
                    num+=st.top();
                    st.pop();
                }
                // reverse 321 to 123
                reverse(num.begin(),num.end());
                int n=stoi(num);
            

                //final decoding 
                string currdecode="";
                while(n--){
                    currdecode+=stringtorepeat;
                }
                st.push(currdecode);
            }
            else 
            {
                string temp(1,ch);///convert char to string
                st.push(temp);
            }
        }
        ///ye mujhe sari stirng dedega abh m inko final rev karke ans return kardunga 
                string ans="";
                while(!st.empty()){
                    ans+=st.top();
                    st.pop();
                }
                reverse(ans.begin(),ans.end());
                return ans;
    }
};