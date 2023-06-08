class Solution {
public:
    int isWinner(vector<int>& player1, vector<int>& player2) {
        int n1=player1.size(),n2=player2.size(),ans1=0,ans2=0,x1=0,x2=0;
        
        for(int i=0;i<n1;i++){
            ans1+=player1[i];
            ans2+=player2[i];
            
            if(x1){
                x1--;
                ans1+=player1[i];
            }
            if(x2){
                x2--;
                ans2+=player2[i];
            }
            if(player1[i] == 10){
                x1=2;
            }
            if(player2[i] == 10){
                x2=2; 
            }
        }
        if(ans1 > ans2)
            return 1;
        else if(ans1 < ans2)
            return 2;
        else
            return 0;
    }
};