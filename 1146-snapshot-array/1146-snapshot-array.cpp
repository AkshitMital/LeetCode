class SnapshotArray {
private:
    int snap_id;
    vector<vector<pair<int,int>>> vec;
public:
    SnapshotArray(int length) {
        snap_id = 0;
        vec.resize(length);
        for(int i = 0; i < length; i++){
            vec[i].push_back({0,0});
        }
    }
    
    void set(int index, int val) {
        vec[index].push_back({snap_id, val});
    }
    
    int snap() {
        snap_id++;
        return snap_id-1;
    }
    
    int get(int index, int snap_id) {
        auto it = upper_bound(vec[index].begin(), vec[index].end(), make_pair(snap_id, INT_MAX));
        if (it == vec[index].begin()) return 0;
        it--;
        return it->second;
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */