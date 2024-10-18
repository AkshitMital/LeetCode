class LFUCache {
private:
    int size;
    int cap;

    unordered_map<int, list<vector<int>>::iterator> mpp;
    map<int,list<vector<int>>> freq; // key, value, frequency
public:
    LFUCache(int capacity) {
        cap = capacity;
        size = 0;
    }

    void makeMostFrequentlyUsed(int key){
        auto &vec = (*mpp[key]);

        int val = vec[1];
        int counter = vec[2];

        freq[counter].erase(mpp[key]);
        if(freq[counter].empty()) freq.erase(counter);

        counter++;
        freq[counter].push_front({key, val, counter});

        mpp[key] = freq[counter].begin();
    }
    
    int get(int key) {
        if(mpp.find(key) == mpp.end()) return -1;

        auto vec = (*mpp[key]);
        int val = vec[1];
        makeMostFrequentlyUsed(key);

        return val;
    }
    
    void put(int key, int value) {
        if(cap == 0) return;

        if(mpp.find(key) != mpp.end()){
            auto &vec = (*mpp[key]);
            vec[1] = value;
            makeMostFrequentlyUsed(key);
        }
        else if(size < cap){
            freq[1].push_front({key, value, 1});
            mpp[key] = freq[1].begin();
            size++;
        }
        else{
            auto &firstList = freq.begin()->second;
            int delKey = (firstList.back())[0];

            firstList.pop_back();
            if(firstList.empty()) freq.erase(freq.begin()->first);
            mpp.erase(delKey);

            freq[1].push_front({key, value, 1});
            mpp[key] = freq[1].begin();
            size++;
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */