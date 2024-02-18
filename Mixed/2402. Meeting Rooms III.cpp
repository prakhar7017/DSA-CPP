class Solution {
public:
    typedef pair<long long,int> T;
    int mostBooked(int n, vector<vector<int>>& meetings) {
        int m=meetings.size();
        vector<int>roomUsedCount(n,0);
        sort(meetings.begin(),meetings.end());

        priority_queue<T,vector<T>,greater<T>>roomsUsed;
        priority_queue<int,vector<int>,greater<int>>roomsAvailable;

        for(int room=0;room<n;room++){
            roomsAvailable.push(room);
        }

        for(vector<int>&meet:meetings){
            int start=meet[0];
            int end=meet[1];
            int duration=end-start;

            while(!roomsUsed.empty() && roomsUsed.top().first<=start){
                int roomNo=roomsUsed.top().second;
                roomsUsed.pop();
                roomsAvailable.push(roomNo);
            }

            if(!roomsAvailable.empty()){
                int roomNo=roomsAvailable.top();
                roomsAvailable.pop();
                roomsUsed.push({end,roomNo});
                roomUsedCount[roomNo]++;
            }else{ // no rooms available
                int roomNo=roomsUsed.top().second;
                long long entTime=roomsUsed.top().first;
                roomsUsed.pop();
                roomsUsed.push({entTime+duration,roomNo});
                roomUsedCount[roomNo]++;
            }
        }

        int result=-1;
        int maxUse=0;
        for(int room=0;room<n;room++){
            if(roomUsedCount[room]>maxUse){
                maxUse=roomUsedCount[room];
                result=room;
            }
        }
        return result;
        
    }
};