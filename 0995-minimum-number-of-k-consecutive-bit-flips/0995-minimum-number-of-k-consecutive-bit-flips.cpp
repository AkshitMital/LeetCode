class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = 0;
        int flipCount = 0;

        for(int i = 0; i < n; i++){
            if(i >= k && nums[i-k] == 1e9){
                flipCount--;
            }
            if(flipCount % 2 == nums[i]){
                if(i+k > n) return -1;
                ans++;
                flipCount++;
                nums[i] = 1e9;
            }
        }

        return ans;
    }
};