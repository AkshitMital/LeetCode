class Solution {
public:
    long long findScore(vector<int>& nums) {
        int n = nums.size();
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> min_pq;

        vector<int> vis(n, 0);
        for(int i = 0; i < nums.size(); i++) min_pq.push({nums[i], i});

        long long ans = 0;
        while(!min_pq.empty()){
            auto [val, idx] = min_pq.top();
            min_pq.pop();
            if(vis[idx]) continue;
            vis[idx] = 1;
            if(idx + 1 < n) vis[idx + 1] = 1;
            if(idx - 1 >= 0) vis[idx - 1] = 1;

            ans += val;
        }
        
        return ans;
    }
};