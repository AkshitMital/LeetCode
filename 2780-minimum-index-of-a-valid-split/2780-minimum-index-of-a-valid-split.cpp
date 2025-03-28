class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        int n = nums.size();

        unordered_map<int, int> mpp1;
        unordered_map<int, int> mpp2;

        for(int& num : nums) mpp2[num]++;

        for(int i = 0; i < n; i++) {
            int num = nums[i];

            mpp1[num]++;
            mpp2[num]--;

            int n1 = i + 1;
            int n2 = n - i - 1;
            if(mpp1[num] * 2 > n1 && mpp2[num] * 2 > n2) return i;
        }

        return -1;
    }
};