class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int n = arr.size(), MOD = 1e9 + 7;

        int odd = 0, even = 1, sum = 0, count = 0;
        for(int i = 0; i < n; i++) {
            sum += arr[i];

            if(sum % 2 == 0) { // odd + even = odd
                count = (count + odd) % MOD;
                even++;
            } else { // even + odd = odd
                count = (count + even) % MOD;
                odd++;
            }
        }

        return count;
    }
};