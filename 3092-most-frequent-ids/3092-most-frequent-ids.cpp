class Solution {
public:
    vector<long long> mostFrequentIDs(vector<int>& nums, vector<int>& freq) {
        int n = nums.size();
        unordered_map<long long, long long> mpp;
        vector<long long> ans(n,0);
        priority_queue<pair<long long, long long>> pq;
        for(int i = 0; i < n; i++){
            int ID = nums[i];
            int f = freq[i];

            mpp[ID] += f;
            pq.push({mpp[ID], ID});

            while(mpp[pq.top().second] != pq.top().first){
                pq.pop();
            }

            ans[i] = pq.top().first;
        }

        return ans;
    }
};