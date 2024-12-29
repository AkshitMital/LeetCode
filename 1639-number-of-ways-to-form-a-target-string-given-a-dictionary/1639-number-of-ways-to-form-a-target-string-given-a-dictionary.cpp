class Solution {
private:
    const int MOD = 1e9+7;

    int solve(int i, int j, vector<vector<long long>>& freq, vector<string>& words, string& target, int &m, int &k, vector<vector<int>>& dp){
        if(j == m) return 1;
        if(i == k) return 0;
        if(dp[i][j] != -1) return dp[i][j];

        int not_take = solve(i + 1, j, freq, words, target, m, k, dp) % MOD;
        int take = freq[target[j] - 'a'][i] * solve(i + 1, j + 1, freq, words, target, m, k, dp) % MOD;

        return dp[i][j] = (take + not_take) % MOD;
    }
public:
    int numWays(vector<string>& words, string target) {
        int k = words[0].length(), n = words.size(), m = target.size();
        vector<vector<long long>> freq(26, vector<long long>(k, 0));

        for(auto word : words){
            for(int idx = 0; idx < k; idx++){
                freq[word[idx] - 'a'][idx]++;
            }
        }

        vector<vector<int>> dp(1001, vector<int>(1001, -1));
        return solve(0, 0, freq, words, target, m, k, dp);
    }
};