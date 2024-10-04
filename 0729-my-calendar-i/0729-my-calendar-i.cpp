class MyCalendar {
set<pair<int,int>> st;
public:
    MyCalendar() {}
    
    bool book(int start, int end) {
        pair<int,int> curr = {start, end};

        auto it = lower_bound(st.begin(), st.end(), curr);
        if(it != st.end() && it->first < end) return false;

        if(it != st.begin()){
            auto prevIt = prev(it);
            if(prevIt->second > start) return false;
        }

        st.insert(curr);

        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */