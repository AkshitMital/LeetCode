class Solution {
private:
    vector<string> columnStates;
    const int MOD = 1e9 + 7;

    void generateStates(string currState, int length, char prevColor, int& m, int& n) {
        if(length == m) {
            columnStates.push_back(currState);
            return;
        }

        for(char color : {'R', 'G', 'B'}) {
            if(color == prevColor) continue;
            generateStates(currState + color, length + 1, color, m, n);
        }
    }

    int solve(int prevStateIdx, int remainCols, int& m, int& n, vector<vector<int>>& dp) {
        if(remainCols == 0) return 1;
        if(dp[remainCols][prevStateIdx] != -1) return dp[remainCols][prevStateIdx];
        int ways = 0;
        string prevState = columnStates[prevStateIdx];

        for(int i = 0; i < columnStates.size(); i++) {
            string curr = columnStates[i];
            bool valid = true;

            for(int j = 0; j < m; j++) {
                if(prevState[j] == curr[j]) {
                    valid = false;
                    break;
                }
            }
            if(valid) {
                ways = (ways + solve(i, remainCols - 1, m, n, dp)) % MOD;
            }
        }

        return dp[remainCols][prevStateIdx] = ways;
    }
public:
    int colorTheGrid(int m, int n) {
        generateStates("", 0, '#', m, n);

        vector<vector<int>> dp(n, vector<int>(columnStates.size(), -1));

        int result = 0;
        for(int i = 0; i < columnStates.size(); i++) {
            result = (result + solve(i, n - 1, m, n, dp)) % MOD;
        }

        return result;
    }
};