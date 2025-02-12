class Solution {
private:
    int sumOfDigits(int num) {
        int sum = 0;
        while(num) {
            sum += (num % 10);
            num /= 10;
        }

        return sum;
    }
public:
    int maximumSum(vector<int>& nums) {
        unordered_map<int, priority_queue<int>> mpp;

        for(int& num : nums) {
            int sum = sumOfDigits(num);
            mpp[sum].push(num);
        }

        int ans = -1;
        for(auto& [sum, pq] : mpp) {
            if(pq.size() == 1) continue;

            int currSum = pq.top();
            pq.pop();
            currSum += pq.top();

            ans = max(currSum, ans);
        }

        return ans;
    }
};