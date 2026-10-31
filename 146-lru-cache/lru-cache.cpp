// class LRUCache {
// public:
//     typedef pair<int,int>P; //{key,value}
//     vector<P>cache;// jo fresh hh wo last ma hh; front ma delete hone wale pair honge.
//     int n;
//     LRUCache(int capacity) {
//         n = capacity;
//     }
    
//     int get(int key) {
//         for(int i=0;i<cache.size();i++){
//             if(cache[i].first == key){
//                 int val = cache[i].second; // store val
//                 P temp = cache[i]; // store pair
//                 cache.erase(cache.begin()+i); // delete that pair,
//                 cache.push_back(temp); // push it back
//                 return val;
//             }
//         }
//         return -1;
//     }
    
//     void put(int key, int value) {
//         for(int i=0;i<cache.size();i++){
//             if(cache[i].first == key){
//                 cache.erase(cache.begin()+i);
//                 cache.push_back({key,value});
//                 return;
//             }
//         }

//         if(cache.size() == n){
//             cache.erase(cache.begin());
//             cache.push_back({key,value});
//         }else{
//             cache.push_back({key,value});
//         }
//     }
// };

class LRUCache {
public:
    typedef pair<list<int>::iterator,int>P; //{key,value}
    list<int>dll; //key
    unordered_map<int,P>mp;
    int n;
    LRUCache(int capacity) {
        n = capacity;
    }

    void makeMostRecently(int key){
        dll.erase(mp[key].first);
        dll.push_front(key);
        mp[key].first = dll.begin();
    }
    
    int get(int key) {
        if(mp.find(key)==mp.end()) return -1;
        makeMostRecently(key);
        return mp[key].second;
    }
    
    void put(int key, int value) {
        if(mp.find(key)!=mp.end()){
            mp[key].second = value;
            makeMostRecently(key);
            return;
        }else{
            dll.push_front(key);
            mp[key]= {dll.begin(),value};
            n--;
        }

        if( n < 0 ){
            int key_to_delete = dll.back();
            mp.erase(key_to_delete);
            dll.pop_back();
            n++;
        }
    }
};

