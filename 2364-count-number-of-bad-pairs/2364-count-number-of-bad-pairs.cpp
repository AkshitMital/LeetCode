class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        unordered_map<int,int> mpp;
        long long badPairs = 0;

        mpp[nums[0]] = 1;

        for(int i = 1; i < nums.size(); i++) {
            int numsBeforeIndex = mpp[nums[i] - i];

            int totalPairsBeforeIndex = i;

            int currBadPairs = totalPairsBeforeIndex - numsBeforeIndex;

            badPairs += currBadPairs;

            mpp[nums[i] - i]++;
        }

        return badPairs;
    }
};