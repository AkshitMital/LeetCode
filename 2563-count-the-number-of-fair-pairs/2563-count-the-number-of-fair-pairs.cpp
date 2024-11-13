class Solution {
private:
    long long BinarySearch(vector<int>& nums, int l, int r, int target){
        while(l <= r){
            long long mid = r + (l-r)/2;
            if(nums[mid] >= target) r = mid - 1;
            else l = mid + 1;
        }

        return r;
    }
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        long long cnt = 0;
        for(int i = 0; i < n; i++){
            int low = lower - nums[i];
            int up = upper - nums[i];
            cnt += (BinarySearch(nums, i+1, n-1, up+1) - BinarySearch(nums, i+1, n-1, low));
        }

        return cnt;
    }
};