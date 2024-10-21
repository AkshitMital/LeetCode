class Solution {
private:
    void solve(int i, string s, unordered_set<string>& st, int currCount, int& maxCount){
        if(i >= s.length()){
            maxCount = max(maxCount, currCount);
            return;
        }

        for(int j = i; j < s.length(); j++){
            string temp = s.substr(i, j-i+1);
            if(st.find(temp) == st.end()){
                st.insert(temp);
                solve(j + 1, s, st, currCount+1, maxCount);
                st.erase(temp);
            }
        }
    }
public:
    int maxUniqueSplit(string s) {
        unordered_set<string> st;
        int maxCount = 0;
        solve(0, s, st, 0, maxCount);

        return maxCount;
    }
};