class Solution {
private:
    const int MOD = 1e9 + 7;
    int findPower(long long a, long long b) {
        if(b == 0) return 1;
        long long half = findPower(a, b / 2);
        long long result = (half * half) % MOD;
        if(b % 2 == 1) result = (result * a) % MOD;
        return result;
    }

    vector<int> getPrimes(int limit) {
        vector<bool> isPrime(limit + 1, true);
        vector<int> primes;

        for(int i = 2; i*i <= limit; i++) {
            if(isPrime[i]) {
                for(int j = i*i; j <= limit; j+=i) {
                    isPrime[j] = false;
                }
            }
        }

        for(int i = 2; i <= limit; i++) {
            if(isPrime[i]) primes.push_back(i);
        }

        return primes;
    }

    vector<int> findPrimeScores(vector<int>& nums) {
        int n = nums.size();
        vector<int> primeScores(n, 0);

        int maxi = *max_element(nums.begin(), nums.end());
        vector<int> primes = getPrimes(maxi); //O(mloglogm)

        for(int i = 0; i < n; i++) {
            int num = nums[i];

            for(int prime : primes) {
                if(prime*prime > num) break;

                if(num % prime != 0) continue;

                primeScores[i]++;
                while(num%prime == 0) num /= prime;
            }
            if(num > 1) primeScores[i]++;
        }

        return primeScores;
    }

    vector<int> findNextGreater(vector<int>& primeScores) {
        int n = primeScores.size();
        stack<int> st;
        vector<int> nextGreater(n, n);

        for(int i = n - 1; i >= 0; i--) {
            while(!st.empty() && primeScores[st.top()] <= primeScores[i]) st.pop();

            nextGreater[i] = (st.empty()) ? n : st.top();
            st.push(i);
        }

        return nextGreater;
    }

    vector<int> findPrevGreater(vector<int>& primeScores) {
        int n = primeScores.size();
        stack<int> st;
        vector<int> prevGreater(n, -1);

        for(int i = 0; i < n; i++) {
            while(!st.empty() && primeScores[st.top()] < primeScores[i]) st.pop();

            prevGreater[i] = (st.empty()) ? -1 : st.top();
            st.push(i);
        }

        return prevGreater;
    }
public:
    int maximumScore(vector<int>& nums, int k) {
        vector<int> primeScores = findPrimeScores(nums); //O(mloglogm + n*log(m))
        vector<int> nextGreater = findNextGreater(primeScores); //O(n)
        vector<int> prevGreater = findPrevGreater(primeScores); //O(n)

        int n = nums.size();
        vector<long long> subarrays(n, 0);

        for(int i = 0; i < n; i++) {
            subarrays[i] = (long long) (nextGreater[i] - i) * (i - prevGreater[i]);
        }

        vector<pair<int, int>> sortedNums(n);
        for(int i = 0; i < n; i++) {
            sortedNums[i] = {nums[i], i};
        }

        sort(begin(sortedNums), end(sortedNums), greater<>()); //O(nlogn)

        long long score = 1;
        int idx = 0;
        while(k > 0) {
            auto [num, i] = sortedNums[idx];
            long long operations = min((long long)k, subarrays[i]);

            score = (score * findPower(num, operations)) % MOD;

            k -= operations;
            idx++;
        }

        return score;
    }
};