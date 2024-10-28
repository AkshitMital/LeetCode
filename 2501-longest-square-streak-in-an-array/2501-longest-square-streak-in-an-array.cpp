class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        unordered_map<int,int> mpp;
        for(int i = 0; i < n; i++) mpp[nums[i]] = i;
        vector<int> vis(n, 1);

        int maxCount = 0;
        for(int i = 0; i < n; i++){
            long long num = (long) nums[i];
            int count = 0;
            while(mpp.find(num) != mpp.end() && vis[mpp[num]] == 1){
                vis[mpp[num]] = 0;
                num = num * num;
                count++;
            }

            maxCount = max(count, maxCount);
        }

        return (maxCount == 1) ? -1 : maxCount;
    }
};