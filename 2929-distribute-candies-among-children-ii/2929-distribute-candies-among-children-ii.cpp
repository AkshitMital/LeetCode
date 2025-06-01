class Solution {
public:
    long long distributeCandies(int n, int limit) {
        long long ways = 0;
        int ch1Min = max(0, n - 2*limit);
        int ch1Max = min(n, limit);

        for(int i = ch1Min; i <= ch1Max; i++) {
            int N = n - i;

            int minCh2 = max(0, N-limit);
            int maxCh2 = min(N, limit);

            ways += (maxCh2 - minCh2 + 1);
        }

        return ways;
    }
};