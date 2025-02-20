class Solution {
private:
    void solve(string& curr, string& res, unordered_set<string>& st, int& n) {
        if(curr.length() == n) {
            if(st.find(curr) == st.end()) res = curr;
            return;
        }

        for(char ch = '0'; ch <= '1'; ch++) {
            curr.push_back(ch);
            solve(curr, res, st, n);
            curr.pop_back();
        }
    }
public:
    string findDifferentBinaryString(vector<string>& nums) {
        unordered_set<string> st(nums.begin(), nums.end());

        int n = nums.size();
        string res = "";
        string curr = "";
        solve(curr, res, st, n);

        return {res};
    }
};