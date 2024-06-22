class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        int l = 0, m = 0, odd = 0, ans = 0;

        for(int r = 0; r < n; r++){
            if(nums[r] % 2 == 1) odd++;

            while(odd > k){
                if(nums[l] % 2 == 1) odd--;
                l++;
                m = l;
            }

            if(odd == k){
                while(m <= r && nums[m] % 2 == 0) m++;
                ans += (m - l + 1);
            }
        }

        return ans;
    }
};
