// class Solution {
// public:
//     int MOD = 1e9+7;
//     int rangeSum(vector<int>& nums, int n, int left, int right) {
//         vector<int> subset;
//         for(int i = 0; i < nums.size(); i++){
//             int temp = 0;
//             for(int j = i; j < nums.size(); j++){
//                 temp += nums[j];
//                 subset.push_back(temp);
//             }
//         }

//         sort(subset.begin(), subset.end());

//         int ans = 0;
//         for(int i = left-1; i < right; i++){
//             ans = (ans + subset[i])%MOD;
//         }

//         return ans%MOD;
//     }
// };

class Solution {
public:
    int MOD = 1e9+7;
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        
        for(int i = 0; i < n; i++){
            pq.push({nums[i], i});
        }
        
        int res = 0;

        for(int cnt = 1; cnt <= right; cnt++){
            int sum = pq.top().first;
            int idx = pq.top().second;
            pq.pop();
            
            if(cnt >= left) res = (res + sum) % MOD;

            int new_idx = idx + 1;
            if(new_idx < n) pq.push({sum + nums[new_idx], new_idx});

        }

        return res;
    }
};