class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int n = nums.size();

        priority_queue<pair<int,int>> max_pq;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> min_pq;

        int i = 0, j = 0, ans = 0;

        while(j < n){
            max_pq.push({nums[j], j});
            min_pq.push({nums[j], j});

            if(max_pq.top().first - min_pq.top().first > limit){
                i = min(max_pq.top().second, min_pq.top().second) + 1;
                while(max_pq.top().second < i){
                    max_pq.pop();
                }
                while(min_pq.top().second < i){
                    min_pq.pop();
                }
            }

            ans = max(ans, j - i + 1);
            j++;
        }

        return ans;
    }
};