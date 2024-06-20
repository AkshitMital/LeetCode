class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size(), m = word2.size();
        vector<int> prev(m+1,0), curr(m+1,0);

        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                if(word1[i-1] == word2[j-1]) curr[j] = 1 + prev[j-1];
                else curr[j] = max(prev[j], curr[j-1]);
            }
            prev = curr;
        }

        int len = prev[m];
        int ans = 0;

        // if(len == n) ans = (m-len);
        // else if(len == m) ans = (n-len);
        // else ans = (n+m) - 2*len;

        // return ans;

        return ((n+m) - 2*len);
    }
};