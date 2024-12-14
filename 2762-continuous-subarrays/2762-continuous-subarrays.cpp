class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        int n = nums.size();

        priority_queue<pair<int, int>> max_pq;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> min_pq;

        int i = 0, j = 0; 
        long long count = 0;

        while(j < n){
            min_pq.push({nums[j], j});
            max_pq.push({nums[j], j});

            while(abs(max_pq.top().first - min_pq.top().first) > 2) {
                i++;

                while(!max_pq.empty() && max_pq.top().second < i) max_pq.pop();
                while(!min_pq.empty() && min_pq.top().second < i) min_pq.pop();
            }

            count += (j - i + 1);
            j++;
        }

        return count;
    }
};