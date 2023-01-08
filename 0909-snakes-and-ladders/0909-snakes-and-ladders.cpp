class Solution {
public:
    int BFS(vector<vector<int>>& board, unordered_map<int,int> &mp, vector<int> &visited, int n)
{
    queue<pair<int,int>> Q;
    
    pair<int,int> start = make_pair(0,0);
    
    Q.push(start);
    
    while(!Q.empty())
    {
        auto curr = Q.front();
        Q.pop();
        
        int currSq = curr.first;
        int currSteps = curr.second;
        
        for(int i=1;i<7;i++)
        {
            int newSq = currSq + i;
                            
            if( mp.find(newSq) != mp.end())
                newSq = mp[newSq];
            
            if( newSq == (n*n)-1 ) return currSteps+1;

            if(!visited[newSq])
            {
                cout<<"currSq is "<<currSq<<" "<<" newSq is "<<newSq<<endl;
                cout<<"currSteps is "<<currSteps<<" newSteps is "<<currSteps+1<<endl;
                Q.push(make_pair(newSq,currSteps+1));
                visited[newSq] = 1;
            }
                
                
        }
    }
    
    return -1;
    
}

int snakesAndLadders(vector<vector<int>>& board) {

    int n = board.size();
    unordered_map<int,int> mp;
    vector<int> visited(n*n, 0);
    
    
    //We reverse the board to make our traversing through indexes easier / more intuitive
    reverse(board.begin(),board.end());
    
    //for every odd row we reverse the row because the traversal of the board is alternating and we need to traverse it that way
    for(int i=0;i<n;i++)
        if(i%2)
            reverse(board[i].begin(),board[i].end());
    
    //we create a map of snakes and ladders 
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(board[i][j] != -1)
                mp[(i*n) + j] = board[i][j] - 1; 
        }
    }
       
    //BFS
    return BFS(board, mp, visited, n);
    
    
}
};