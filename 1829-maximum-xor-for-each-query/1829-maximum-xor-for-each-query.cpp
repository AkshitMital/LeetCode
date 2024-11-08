class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int n = nums.size();
        int maxXOR = pow(2, maximumBit) - 1;
        vector<int> answer(n, 0);

        for(int i = 1; i < n; i++){
            nums[i] = nums[i] ^ nums[i-1];
        }

        for(int i = n-1; i >= 0; i--){
            answer[n-i-1] = nums[i] ^ maxXOR;
        }

        return answer;
    }
};