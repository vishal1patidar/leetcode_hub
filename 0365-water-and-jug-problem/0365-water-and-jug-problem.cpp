class Solution {
public:
    bool canMeasureWater(int jug1Capacity, int jug2Capacity, int targetCapacity) {
        
        int x=jug1Capacity,y=jug2Capacity,z=x+y;
        int steps[]={x,-x,-y,y}; //STEPS THAT CAN BE PERFORMED
        
        queue<int> q;
        vector<int> vis(z+1,0); // VISITED ARRAY TO KEEP NOT ITERATING THE SAME VALUES OVER AND OVER AGAIN
        q.push(0);
        vis[0]=1;
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            
            if(node==targetCapacity)
            {
                return true; // WHEN WE FIND THE TARGET CAPACITY ACHIEVED
            }
            for(int i=0;i<4;i++)
            {
                int newNode=node+steps[i];
                if(newNode>=0 && newNode<=z && vis[newNode]==0) //BOUNDARY CHECKS 
                {
                    q.push(newNode);
                    vis[newNode]=1;
                }
            }
        }
        return false; // IF TARGET CAPACITY CAN NEVER BE ACHIVED
    }
};