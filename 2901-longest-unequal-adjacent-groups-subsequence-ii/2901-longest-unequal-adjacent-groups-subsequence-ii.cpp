class Solution {
private:
    bool checkHammingDistance(string& word1, string& word2) {
        int distance = 0;
        for(int i = 0; i < word1.length(); i++) {
            if(word1[i] != word2[i]) distance++;
            if(distance > 1) return false;
        }

        return distance == 1;
    }
public:
    vector<string> getWordsInLongestSubsequence(vector<string>& words, vector<int>& groups) {
        int n = words.size();
        vector<int> dp(n, 1), parent(n, -1);
        int longestSub = 1, longestSubIdx = 0;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < i; j++) {
                if(groups[i] != groups[j] && words[i].length() == words[j].length() && checkHammingDistance(words[i], words[j])) {
                    if(dp[j] + 1 > dp[i]) {
                        dp[i] = dp[j] + 1;
                        parent[i] = j;

                        if(longestSub < dp[i]) {
                            longestSub = dp[i];
                            longestSubIdx = i;
                        }
                    }
                }
            }
        }

        vector<string> result;
        while(longestSubIdx != -1) {
            result.push_back(words[longestSubIdx]);
            longestSubIdx = parent[longestSubIdx];
        }

        reverse(result.begin(), result.end());

        return result;
    }
};