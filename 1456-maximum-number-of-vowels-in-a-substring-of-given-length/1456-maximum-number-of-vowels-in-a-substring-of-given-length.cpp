class Solution {
public:
    int isVowel(char c){
        if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u')
            return 1;
        return 0;
    }

    int maxVowels(string s, int k) {
        int max_vow = 0, cur_vow=0;
        for(int i=0;i<s.size();i++){
            cur_vow += isVowel(s[i]);
            if(i>=k)
                cur_vow -= isVowel(s[i-k]);
            max_vow = max(max_vow, cur_vow);
        }
        return max_vow;    
    }
};