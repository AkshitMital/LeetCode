class Solution {
public:
    bool judgeSquareSum(int c) {
        unordered_set<int> st;
        for(int b = 0; b <= sqrt(c); b++){
            st.insert(b*b);
            int a = c - (b*b);
            if (st.find(a) != st.end()) return true;
        }
        return false;
    }
};