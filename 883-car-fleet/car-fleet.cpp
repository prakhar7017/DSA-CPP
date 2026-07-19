class Solution {
public:
    typedef pair<int,int>P;
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        vector<P>arr;
        for(int i=0;i<n;i++) {
            arr.push_back({position[i],speed[i]});
        }
        sort(begin(arr),end(arr));
        int fleet = 0;
        double fleetTime = 0.0;
        for(int i=n-1;i>=0;i--){
            double currTime = double(target - arr[i].first)/arr[i].second;
            if(currTime > fleetTime){
                fleet++;
                fleetTime = currTime;
            }
        }
        return fleet;
    }
};