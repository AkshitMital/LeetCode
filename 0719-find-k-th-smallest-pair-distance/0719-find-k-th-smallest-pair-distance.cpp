class Solution {
private:
    int slidingWindow(vector<int>& nums, int dist) {
        int i = 0, j = i + 1, countPairs = 0;
        while(j < nums.size()){
            int diff = nums[j] - nums[i];
            if(diff <= dist) {
                countPairs += (j-i);
                j++;
            }
            else {
                i++;
                if(i == j) j++;
            }
        }

        return countPairs;
    }
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int ans = 0, n = nums.size(), l = 0, r = nums[n-1] - nums[0];
        while(l <= r){
            int mid = l + (r-l)/2;

            int countPairs = slidingWindow(nums, mid);

            if(countPairs < k) l = mid + 1;
            else {
                ans = mid;
                r = mid - 1;
            }
        }

        return ans;
    }
};