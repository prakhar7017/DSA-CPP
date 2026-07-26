class TimeMap {
public:
    typedef pair<int,string>P;
    unordered_map<string,vector<P>>mp;
    TimeMap() {}
    string bruteForce(string key, int timestamp){
        if(mp.find(key)==mp.end()) return "";
        vector<P>& values = mp[key];
        for(int i=values.size()-1;i>=0;i--){
            int timeS = values[i].first;
            if(timeS<=timestamp) return values[i].second;
        }
        return "";
    }
    string binarySearch(string key, int timestamp){
        if(mp.find(key)==mp.end()) return "";
        vector<P>& values = mp[key];
        int s = 0;
        int e = values.size()-1;
        string ans="";
        while(s<=e){
            int mid = s+(e-s)/2;
            if(values[mid].first<=timestamp){
                ans = values[mid].second;
                s = mid +1 ;
            }else{
                e = mid - 1;
            }
        }
        return ans;
    }
    void set(string key, string value, int timestamp) {
        mp[key].push_back({timestamp,value});
    }
    string get(string key, int timestamp) {
        return binarySearch(key,timestamp);
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */