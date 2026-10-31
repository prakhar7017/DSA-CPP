class LRUCache {
public:
    typedef pair<int,int>P; //{key,value}
    vector<P>cache;// jo fresh hh wo last ma hh; front ma delete hone wale pair honge.
    int n;
    LRUCache(int capacity) {
        n = capacity;
    }
    
    int get(int key) {
        for(int i=0;i<cache.size();i++){
            if(cache[i].first == key){
                int val = cache[i].second; // store val
                P temp = cache[i]; // store pair
                cache.erase(cache.begin()+i); // delete that pair,
                cache.push_back(temp); // push it back
                return val;
            }
        }
        return -1;
    }
    
    void put(int key, int value) {
        for(int i=0;i<cache.size();i++){
            if(cache[i].first == key){
                cache.erase(cache.begin()+i);
                cache.push_back({key,value});
                return;
            }
        }

        if(cache.size() == n){
            cache.erase(cache.begin());
            cache.push_back({key,value});
        }else{
            cache.push_back({key,value});
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */