class Solution {
private:
    bool solve(int i, int j, string s, string p, vector<vector<int>>& dp){
        if(j == p.length())
            return i == s.length();

        if(dp[i][j] != -1) return dp[i][j];

        bool firstCharMatched = false, ans = false;
        if(i < s.length() && (s[i] == p[j] || p[j] == '.')) firstCharMatched = true;

        if(j+1 < p.length() && p[j+1] == '*'){
            bool not_take = solve(i, j+2, s, p, dp);
            bool take = firstCharMatched && solve(i+1, j, s, p, dp);

            ans = not_take || take;
        }
        else ans = firstCharMatched && solve(i+1, j+1, s, p, dp);

        return dp[i][j] = ans;
    }
public:
    bool isMatch(string s, string p) {
        vector<vector<int>> dp(s.length() + 1, vector<int>(p.length() + 1, -1));
        return solve(0, 0, s, p, dp);
    }
};

// class Solution {
// public:
//     int t[21][21];

//     bool solve(int i, int j, string& text, string& pattern) {
//         if (j == pattern.length())
//             return i == text.length();
            
//         if (t[i][j] != -1) {
//             return t[i][j];
//         }
        
//         bool ans = false;

//         bool first_match = (i < text.length() &&
//                             (pattern[j] == text[i] || pattern[j] == '.'));

//         if (j + 1 < pattern.length() && pattern[j + 1] == '*') {
//             ans = (solve(i, j + 2, text, pattern) ||
//                    (first_match && solve(i + 1, j, text, pattern)));
//         } else {
//             ans = first_match && solve(i + 1, j + 1, text, pattern);
//         }

//         return t[i][j] = ans;
//     }
    
//     bool isMatch(string text, string pattern) {
//         memset(t, -1, sizeof(t));
//         return solve(0, 0, text, pattern);
//     }
// };