class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> diffArray(n, 0);

        for(auto& query : queries) {
            diffArray[query[0]] += 1;
            if(query[1] + 1 < n) diffArray[query[1] + 1] -= -1;
        }

        vector<int> result(n, 0);
        int cumSum = 0;
        for(int i = 0; i < n; i++) {
            cumSum += diffArray[i];
            result[i] = cumSum;
            if(result[i] < nums[i]) return false;
        }

        return true;
    }
};