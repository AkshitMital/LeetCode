// class LRUCache {
// private:
//     int n;
//     vector<pair<int,int>> cache;
// public:
//     LRUCache(int capacity) {
//         n = capacity;
//     }
    
//     int get(int key) {
//         for(int i = 0; i < cache.size(); i++){
//             if(cache[i].first == key){
//                 int val = cache[i].second;

//                 pair<int, int> temp = cache[i];

//                 cache.erase(cache.begin() + i);
//                 cache.push_back(temp);

//                 return val;
//             }
//         }

//         return -1;
//     }
    
//     void put(int key, int value) {
//         for(int i = 0; i < cache.size(); i++){
//             if(cache[i].first == key){
//                 cache.erase(cache.begin() + i);
//                 cache.push_back({key, value});
//                 return;
//             }
//         }

//         if(cache.size() == n){
//             cache.erase(cache.begin());
//             cache.push_back({key, value});
//         }
//         else cache.push_back({key, value});

//         return;
//     }
// };

class LRUCache {
private:
    int n;
    list<int> cache;
    map<int, pair<list<int>::iterator, int>> DLLMap;
public:
    LRUCache(int capacity) {
        n = capacity;
    }
    
    int get(int key) {
        if(DLLMap.find(key) == DLLMap.end()) return -1;

        int val = DLLMap[key].second;
        auto address = DLLMap[key].first; 
        cache.erase(address);
        cache.push_front(key);
        DLLMap[key].first = cache.begin();

        return val;
    }
    
    void put(int key, int value) {
        if(DLLMap.find(key) != DLLMap.end()){
            auto address = DLLMap[key].first; 
            cache.erase(address);
            cache.push_front(key);
            DLLMap[key].first = cache.begin();
            DLLMap[key].second = value;
        }else{
            cache.push_front(key);
            DLLMap[key] = {cache.begin(), value};
            n--;
        }

        if(n < 0){
            int delkey = cache.back();
            cache.pop_back();
            DLLMap.erase(delkey);
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