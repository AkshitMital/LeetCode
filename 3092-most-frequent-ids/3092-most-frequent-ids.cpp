class Solution {
public:
    vector<long long> mostFrequentIDs(vector<int>& nums, vector<int>& freq) {
        unordered_map<long long, long long> ID_freq;
        priority_queue<pair<long long, long long>> pq;
        int n = nums.size();
        vector<long long> ans(n, INT_MIN);
        for(int i = 0; i < n; i++){
            int id = nums[i];
            int f = freq[i];

            ID_freq[id] += f;
            pq.push({ID_freq[id], id});

            while(ID_freq[pq.top().second] != pq.top().first) pq.pop();

            ans[i] = pq.top().first;
        }

        return ans;
    }
};