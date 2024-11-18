class Solution {
public:
    vector<int> decrypt(vector<int>& codes, int k) {
        int n = codes.size();
        vector<int> res(n, 0);

        if (k == 0) return res;

        vector<int> prefixSum(2 * n, 0);
        prefixSum[0] = codes[0];
        for (int i = 1; i < 2 * n; i++) {
            prefixSum[i] = prefixSum[i - 1] + codes[i%n];
        }

        if (k > 0) {
            for (int i = 0; i < n; i++) {
                res[i] = prefixSum[i + k] - prefixSum[i];
            }
        } else {
            int absK = abs(k);
            for (int i = n; i < 2*n; i++) {
                res[i-n] = prefixSum[i - 1] - prefixSum[i - absK - 1];
            }
        }

        return res;
    }
};
