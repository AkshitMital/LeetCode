class MyHashMap {
private:
    vector<list<pair<int,int>>> map;
    int size;
public:
    MyHashMap() {
        size = 1e4;
        map.resize(1e4);
    }

    int getIdx(int key){
        return key % size;
    }
    
    void put(int key, int value) {
        int idx = getIdx(key);
        for (auto& it : map[idx]) {
            if (it.first == key) {
                it.second = value;
                return;
            }
        }
        map[idx].push_front({key, value});
        return;
    }
    
    int get(int key) {
        int idx = getIdx(key);
        for(auto& it : map[idx]){
            if(it.first == key) return it.second;
        }
        return -1;
    }
    
    void remove(int key) {
        int idx = getIdx(key);
        for(auto it = map[idx].begin(); it != map[idx].end(); it++){
            if(it->first == key){
                map[idx].erase(it);
                return;
            }
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */