class LRUCache {
public:
    typedef pair<list<int>::iterator,int>P; //{address,value}
    list<int>dll;
    unordered_map<int,P>mp;
    int n;
    LRUCache(int capacity) {
        n = capacity;
    }

    void msu(int key){
        // delete it from it pos
        dll.erase(mp[key].first);
        // put in front
        dll.push_front(key);
        // update add in map
        mp[key].first = dll.begin();
    }
    
    int get(int key) {
        //check if key exist in map
        if(mp.find(key) == mp.end()) return -1;
        msu(key);
        return mp[key].second;
        // make msu and return
        // otherwise return -1
    }
    
    void put(int key, int value) {
        // check if ket exist
        // update value make it msu
        // and retunr
        // else
        // put it intolist
        // update map
        // n<0
        // evist last one
        // n--
        if(mp.find(key)!=mp.end()){
            mp[key].second = value;
            msu(key);
            return;
        }else{
            dll.push_front(key);
            mp[key]={dll.begin(),value};
            n--;
        }

        if(n<0){
            int key_to_delete = dll.back();
            mp.erase(key_to_delete);
            dll.pop_back();
            n++;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */