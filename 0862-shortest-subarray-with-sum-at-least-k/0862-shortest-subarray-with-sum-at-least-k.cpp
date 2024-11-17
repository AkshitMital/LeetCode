class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n = nums.size();

        deque<int> dq;
        vector<long long> cummSum(n, 0);

        int res = INT_MAX;
        int i = 0;
        while(i < n){
            if(i == 0) cummSum[i] = nums[i];
            else cummSum[i] = cummSum[i-1] + nums[i];

            if(cummSum[i] >= k) res = min(res, i+1);

            while(!dq.empty() && cummSum[i] - cummSum[dq.front()] >= k){
                res = min(res, i - dq.front());
                dq.pop_front();
            }

            while(!dq.empty() && cummSum[i] <= cummSum[dq.back()]) dq.pop_back();

            dq.push_back(i);
            i++;
        }

        return (res == INT_MAX) ? -1 : res;
    }
};