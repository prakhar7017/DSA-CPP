class RandomizedSet {
public:
    vector<int>v;
    unordered_map<int,int>mp;
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(mp.find(val)!=mp.end()) return false;
        v.push_back(val);
        mp[val]=v.size()-1;
        return true;
    }
    
    bool remove(int val) {
        if(mp.find(val)==mp.end()) return false;
        int index=mp[val];
        int lastElement=v.back();
        v.back()=val;
        v[index]=lastElement;
        mp[lastElement]=index;
        v.pop_back();
        mp.erase(val);
        return true;
    }
    
    int getRandom() {
        int n=v.size();
        int randIndex=rand()%n;
        return v[randIndex];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */

// why used unordered_map?
// because we insert and get random in o(1) time . but when it comes to remove the element we have to traverse the whole vector to find out the index of desired element. which will cost o(n) time . so we used unordered_map to store the index of each element in the vector. so that we can remove the element in o(1) time.