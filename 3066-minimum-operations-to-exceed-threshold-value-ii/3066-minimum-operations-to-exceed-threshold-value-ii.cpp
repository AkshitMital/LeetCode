class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        priority_queue<long long, vector<long long>, greater<long long>> pq;

        for(int& num : nums) pq.push(num);

        int op = 0;
        while(pq.top() < k) {
            long long x = pq.top();
            pq.pop();
            long long y = pq.top();
            pq.pop();

            long long sum = (min(x, y) * 2) + max(x, y);

            pq.push(sum);
            op++;
        }

        return op;
    }
};