class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& arr) {
        int n = arr.size();
        vector<int> dp(n, 1), hash(n), ans;
        sort(arr.begin(), arr.end());
        for(int ind = 0; ind < n; ind++){
            hash[ind] = ind;
            for(int prev = ind-1; prev >= 0; prev--){
                if((arr[ind] % arr[prev] == 0) && 1 + dp[prev] > dp[ind]){
                    dp[ind] = 1 + dp[prev];
                    hash[ind] = prev;
                }
            }
        }

        int ptr = distance(dp.begin(), max_element(dp.begin(), dp.end()));
        while(hash[ptr] != ptr){
            ans.push_back(arr[ptr]);
            ptr = hash[ptr];
        }
        ans.push_back(arr[ptr]);

        return ans;
    }
};