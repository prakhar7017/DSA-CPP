class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        queue<int>q;
        vector<int>vis(n,false);

        q.push(0);
        vis[0]=true;

        while(!q.empty()){
            int currRoom = q.front();
            q.pop();

            for(int key:rooms[currRoom]){
                if(!vis[key]){
                    vis[key]=true;
                    q.push(key);
                }
            }
        }   

        for(bool v:vis){
            if(!v) return false;
        }

        return true;
    }
};