class Solution {
public:
    int myAtoi(string s) {
        long number = 0;
        bool isNegative = false;
        bool signReceived = false;
        bool numberReceived = false;

        for(int i = 0; i < s.size(); i++){
            if(s[i] == ' ' && !numberReceived && !signReceived) continue;
            else if(s[i] == '-'){
                if(signReceived && numberReceived)
                    break;
                else if(signReceived)
                    return 0;
                isNegative = true;
                signReceived = true;
            }
            else if(s[i] == '+'){
                if(signReceived && numberReceived)
                    break;
                else if(signReceived)
                    return 0;
                signReceived = true;
            }
            else if(s[i] >= '0' && s[i] <= '9'){
                numberReceived = true;
                signReceived = true;
                number += s[i] - 48; //48 is ascii for 0
                if(number > pow(2,31) && isNegative){ 
                    number = pow(2,31);
                    break;
                }
                else if(number > pow(2,31) - 1 && !isNegative){ 
                    number = pow(2,31) - 1;
                    break;
                }
                if(i < s.size()-1 && s[i+1] >= '0' && s[i+1] <= '9')number *= 10;
            }
            else break;
        }
        
        return isNegative ? -number : number;
    }
};