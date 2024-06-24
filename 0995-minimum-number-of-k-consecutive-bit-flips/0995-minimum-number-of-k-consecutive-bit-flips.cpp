class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = 0;
        int flipCount = 0;
        unordered_map<int, bool> isFlipped;

        for(int i = 0; i < n; i++){
            if(i >= k && isFlipped[i-k] == true){
                flipCount--;
            }
            if(flipCount % 2 == nums[i]){
                if(i+k > n) return -1;
                ans++;
                flipCount++;
                isFlipped[i]=true;
            }
        }

        return ans;
    }
};