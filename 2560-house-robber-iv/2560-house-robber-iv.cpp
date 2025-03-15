// class Solution {
// private:
//     int solve(int ind, vector<int>& nums, int k, int n, vector<vector<int>>& dp) {
//         if(k == 0) return 0;
//         if(ind >= n) return INT_MAX;
//         if(dp[ind][k] != -1) return dp[ind][k];

//         int take = max(nums[ind], solve(ind + 2, nums, k - 1, n, dp));
//         int not_take = solve(ind + 1, nums, k, n, dp);

//         return dp[ind][k] = min(take, not_take);
//     }
// public:
//     int minCapability(vector<int>& nums, int k) {
//         int n = nums.size();
//         vector<vector<int>> dp(n + 1, vector<int>(k + 1, -1));
//         return solve(0, nums, k, n, dp);
//     }
// };

class Solution {
private:
    bool isPossible(int capability, vector<int>& nums, int k) {
        int house = 0;

        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] <= capability) {
                house++;
                i++;
            }
        }

        return house >= k;
    }
public:
    int minCapability(vector<int>& nums, int k) {
        int l = *min_element(nums.begin(), nums.end());
        int r = *max_element(nums.begin(), nums.end());
        int result = 0;
        while(l <= r) {
            int mid = l + (r - l)/2;

            if(isPossible(mid, nums, k)) {
                result = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }

        return result;
    }
};