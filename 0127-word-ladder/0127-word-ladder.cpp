class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<pair<string,int>> q;
        q.push({beginWord,1});
        unordered_set<string> check(wordList.begin(),wordList.end());
        check.erase(beginWord);

        while(!q.empty()){
            string word=q.front().first;
            int level=q.front().second;  //level coz bfs approach
            q.pop();

            if(word==endWord) return level;

            for(int i=0;i<word.size();i++){  //check for each character
            char og=word[i];
                for(char c='a'; c<='z';c++){ //check whole alphabet for all possibilities
                    word[i]=c;
                    if(check.find(word)!=check.end()){  //if trial word exists in given wordList
                    check.erase(word);
                    q.push({word,level+1});

                    }
                }
                word[i]=og; // so we can now check for next character in original word

            }


        }

        return 0;  //means no sequence

    }
};