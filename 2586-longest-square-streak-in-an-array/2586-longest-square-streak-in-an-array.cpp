// 

class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> st(nums.begin(), nums.end());
        int maxCount = 0;

        for(int i = 0; i < n; i++){
            long long num = (long long) nums[i];
            int count = 0;
            
            while(st.find(num) != st.end()){
                count++;
                if (num * num > 1e5) break;
                num = num * num;
            }

            maxCount = max(count, maxCount);
        }

        return (maxCount < 2) ? -1 : maxCount;
    }
};