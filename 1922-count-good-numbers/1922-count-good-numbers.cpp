class Solution {
    int MOD = 1e9 + 7;
    long long findPower(long long a, long long b) {
        if(b == 0) return 1;

        long long half = findPower(a, b/2);
        long long res = (half * half) % MOD;

        if(b % 2 == 1) res = (res * a) % MOD;

        return res;
    }
public:
    int countGoodNumbers(long long n) {
        return findPower(5, (n+1)/2) * findPower(4, n/2) % MOD;
    }
};