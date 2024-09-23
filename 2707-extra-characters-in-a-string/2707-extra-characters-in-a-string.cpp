class Solution {
private:
    int solve(int index, string& s, unordered_set<string>& st, vector<int>& dp, int& n){
        if(index >= n) return 0;

        if(dp[index] != -1) return dp[index];

        int result = 1 + solve(index + 1, s, st, dp, n);

        for(int j = index; j < n; j++){
            string curr = s.substr(index, j-index+1);
            if(st.find(curr) != st.end()){
                result = min(result, solve(j+1, s, st, dp, n));
            }
        }

        return dp[index] = result;
    }
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        int n = s.length();
        vector<int> dp(n, -1);
        unordered_set<string> st(begin(dictionary), end(dictionary));

        return solve(0, s, st, dp, n);
    }
};