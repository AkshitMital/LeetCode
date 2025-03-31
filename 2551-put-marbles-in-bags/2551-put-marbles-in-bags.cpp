class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        int n = weights.size(), m = n - 1;

        vector<int> pairSum(m, 0);
        for(int i = 0; i < m; i++) {
            pairSum[i] = weights[i] + weights[i + 1];
        }

        sort(pairSum.begin(), pairSum.end());

        long long maxSum = 0, minSum = 0;
        for(int i = 0; i < k - 1; i++) {
            maxSum += pairSum[m - i - 1];
            minSum += pairSum[i];
        }
        
        return maxSum-minSum;
    }
};