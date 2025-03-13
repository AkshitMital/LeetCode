class Solution {
private:
    bool checkWithDifferenceArray(vector<int>& nums, vector<vector<int>>& queries, int index, int n, int q) {
        vector<int> diff(n, 0);

        for(int i = 0; i <= index; i++) {
            int l = queries[i][0];
            int r = queries[i][1];
            int x = queries[i][2];

            diff[l] += x;
            if(r+1 < n) diff[r+1] -= x;
        }

        int cumSum = 0;
        for(int i = 0; i < n; i++) {
            cumSum += diff[i];

            diff[i] = cumSum;
            if(nums[i] - diff[i] > 0) return false;
        }

        return true;
    }
public:
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size(), q = queries.size();

        auto lambda = [](int x){
            return x == 0;
        };
        if(all_of(nums.begin(), nums.end(), lambda)) return 0;

        int l = 0, r = q - 1, res = -1;
        while(l <= r) {
            int mid = l + (r - l)/2;

            if(checkWithDifferenceArray(nums, queries, mid, n, q) == true) {
                res = mid + 1;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }

        return res;
    }
};