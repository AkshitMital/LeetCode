class SeatManager {
private:
    int seat_marker;
    priority_queue<int, vector<int>, greater<int>> min_pq;
public:
    SeatManager(int n) {
        seat_marker = 1;
    }
    
    int reserve() {
        if(!min_pq.empty()){
            int seat = min_pq.top();
            min_pq.pop();
            return seat;
        }
        int seat = seat_marker;
        seat_marker++;
        return seat;
    }
    
    void unreserve(int seatNumber) {
        min_pq.push(seatNumber);
    }
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */