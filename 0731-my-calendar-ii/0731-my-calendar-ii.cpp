// to check overlap between (a1, b1) and (a2, b2) : max(a1, a2) < min(b1, b2)
// to find overlap region between (a1, b1) and (a2, b2) : {max(a1, a2), min(b1, b2)}
class MyCalendarTwo {
private:
    vector<pair<int,int>> final_booking;
    vector<pair<int,int>> double_booking;
    bool checkOverlap(pair<int,int> curr, pair<int,int> region){
        return (max(curr.first, region.first) < min(curr.second, region.second));
    }
public:
    MyCalendarTwo() {}
    
    bool book(int start, int end) {
        pair<int,int> curr = {start, end};

        for(auto region : double_booking){
            if(checkOverlap(curr, region)) return false;
        }

        for(auto booking : final_booking){
            if(checkOverlap(curr, booking)){
                pair<int,int> region = {max(curr.first, booking.first), min(curr.second, booking.second)};
                double_booking.push_back(region);
            }
        }

        final_booking.push_back(curr);
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */