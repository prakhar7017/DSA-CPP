class LRUCache {
public:
    typedef pair<int,int>P;//key,val
    vector<P>cache; // freash at last and old at front
    int n;
    LRUCache(int capacity) {
        n = capacity;
    }
    
    int get(int key) {
        // look for key 
        // if exist return and make it most recellty uses
        // other return -1;
        for(int i=0;i<cache.size();i++){
            if(cache[i].first == key){
                int val = cache[i].second;
                // delete it fron it pos
                P temp = cache[i];
                cache.erase(cache.begin()+i);
                cache.push_back(temp);
                // put it at last
                return val;
            }
        }
        return -1;
    }
    
    void put(int key, int value) {
        // look for key
        // if it exist . update value . and make most recenlty used and retunr
        for(int i=0;i<cache.size();i++){
            if(cache[i].first == key){
                cache.erase(cache.begin()+i);
                cache.push_back({key,value});
                return;
            }
        }



        // if not found.
        if(cache.size() == n){
            cache.erase(cache.begin());
            cache.push_back({key,value});
        }else{
            cache.push_back({key,value});
        }
        // pust it to cache
        // check size, if >n pop elase return
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */