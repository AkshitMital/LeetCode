class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq; // {min_val, {idx, k_idx}}
        
        int left = nums[0][0], right = nums[0][0];
        int k = nums.size();

        for(int i = 0; i < k; i++){
            left = min(left, nums[i][0]);
            right = max(right, nums[i][0]);
            pq.push({nums[i][0], {0, i}});
        }

        vector<int> res = {left, right};

        while(!pq.empty()){
            int val = pq.top().first;
            int idx = pq.top().second.first;
            int k_idx = pq.top().second.second;
            pq.pop();

            idx += 1;
            if(idx == nums[k_idx].size()) break;

            int next_val = nums[k_idx][idx];
            pq.push({next_val, {idx, k_idx}});

            left = pq.top().first;
            right = max(right, next_val);

            if(right - left < res[1] - res[0]){
                res = {left, right};
            }
        }

        return res;
    }
};