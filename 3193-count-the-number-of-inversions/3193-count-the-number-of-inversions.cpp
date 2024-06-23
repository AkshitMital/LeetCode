class Solution {
public:
    int numberOfPermutations(int n, vector<vector<int>>& requirements) 
    {
        vector<long long> arr(n + 1, -1);
        for (auto it : requirements) {
            long long first = it[0];
            long long second = it[1];
            arr[first + 1] = second;
        }

        vector<long long> prev(401, 0);
        prev[0] = 1;
        int MOD = 1e9+7;

        for (int i = 1; i <= n; i++) {
            vector<long long> curr(401, 0);
            
            for (int j = 0; j <= 400; j++) {
                long long sum = 0;
                for (int pos = 0; pos < i && pos <= j; pos++) sum = (sum + prev[j - pos]) % MOD;
                curr[j] = sum;
            }

            if (arr[i] != -1) {
                for (int j = 0; j <= 400; j++) {
                    if (j != arr[i]) curr[j] = 0;
                }
            }
            
            prev = curr;
        }

        long long ans = 0;
        for (auto count : prev) ans = (ans + count) % MOD;

        return ans;
    }
};
