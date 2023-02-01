class TopVotedCandidate{
public:
    vector<int> times;
    map<int,int> winnerAtEachTime;
    TopVotedCandidate(vector<int>& persons,vector<int>& times){
        this->times=times;
        int n=persons.size();
        int mx=INT_MIN,personWithMxVote;
        map<int,int> m;
        for(int i=0;i<n;i++){
            m[persons[i]]++;
            if(m[persons[i]]>=mx){
                mx=m[persons[i]];
                personWithMxVote=persons[i];
            }
            winnerAtEachTime[times[i]]=personWithMxVote;
        }
    }
    int q(int t){
        int lo=0,hi=times.size()-1,ans=winnerAtEachTime[0];
        while(hi>=lo){
            int m=lo+(hi-lo)/2;
            if(times[m]>t) hi=m-1;
            else{
                ans=winnerAtEachTime[times[m]];
                lo=m+1;
            }
        }
        return ans;
    }
};
