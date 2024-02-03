class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        int stops=0;
        int dist=0; // distance travelled
        int fuel=startFuel;
        int i=0;

        priority_queue<pair<int,int>>maxi; // why max heap becouze max fuel station we need to take first
        while(true){
            while(i<stations.size()){
                if(stations[i][0]<=dist+fuel){ // fuel station within reach, jo jo station meri range ma  rahi hai unko max heap ma dal do,or range kese nikalti hh dist+fuel karke jintna travel kiya hh usme fuel add kardo
                    maxi.push({stations[i][1],stations[i][0]});
                }else{
                    break;
                }
                i++;
            }
            // travel with the fuel
            dist+=fuel; // distance travelled
            fuel=0;// fuel khatam hogya

            // reached
            if(dist>=target) break; // khi esa toh nhi ki target tak ya target se jada travel karliya

            // no fuel sattions with reach
            if(maxi.empty()){ // fuel ktam hogya or koi station bhi nhi aya toh -1 return kardo, nhi reach hua target
                stops=-1;
                break;
            }

            // mtlb fuel station toh hh reach ma, toh usse refuel karenge, or usse max heap se nikal denge
            // refuel adjust karenge dist and fuel ko
            auto &top=maxi.top(); // top station with max fuel
            fuel=(dist-top.second)+top.first; // distance travelled from last station to this station + fuel at this station
            // dist-top.second mtlb kitna fuel bacha hh last station se is station tak, or top.first mtlb is station pe kitna fuel hh 
            dist=top.second; // ab ma iss station per hu toh distance bhi utna hi hogya
            maxi.pop();// top station ko nikal do, uska fuel use ho chuka hh
            ++stops;// ek station add kardo
        }
        return stops;
    }
};