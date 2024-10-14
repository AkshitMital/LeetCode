class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<long long> pq;
        for(int num : nums) pq.push(num);
        long long score = 0;
        while(k != 0){
            long long num = pq.top();
            pq.pop();
            score += num;
            num = ceil(num/3.0);
            pq.push(num);
            k--;
        }

        return score;
    }
};