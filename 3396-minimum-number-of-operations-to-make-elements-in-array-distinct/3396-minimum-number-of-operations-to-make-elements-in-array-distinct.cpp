class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        unordered_map<int, int> mpp;
        int n = nums.size(), firstRepeatingNumberIndex = -1;
        for(int i = n-1; i >= 0; i--) {
            if(mpp.find(nums[i]) != mpp.end()) {
                firstRepeatingNumberIndex = i;
                break;
            }

            mpp[nums[i]]++;
        }
        
        return (firstRepeatingNumberIndex + 3) / 3;
    }
};