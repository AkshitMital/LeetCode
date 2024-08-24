class RandomizedSet {
private:
    vector<int> vec;
    unordered_map<int,int> mpp;
public:
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(mpp.find(val) != mpp.end()) return false;

        vec.push_back(val);
        mpp[val] = vec.size() - 1;
        return true;
    }
    
    bool remove(int val) {
        if(mpp.find(val) == mpp.end()) return false;

        int idx = mpp[val];
        int lastElement = vec.back();
        vec.back() = val;
        vec[idx] = lastElement;
        mpp[lastElement] = idx;
        vec.pop_back();
        mpp.erase(val);
        return true;
    }
    
    int getRandom() {
        int randIndx = rand() % vec.size();
        return vec[randIndx];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */