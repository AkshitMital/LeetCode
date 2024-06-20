class Solution {
public:
    int minInsertions(string s) {
        int n = s.length();
        string t = s;
        reverse(t.begin(), t.end());
        vector<int> curr(n+1,0), prev(n+1,0);
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                if(s[i-1] == t[j-1]) curr[j] = 1 + prev[j-1];
                else curr[j] = max(prev[j], curr[j-1]);
            }
            prev = curr;
        }
        int len = prev[n];

        return (n-len);
    }
};