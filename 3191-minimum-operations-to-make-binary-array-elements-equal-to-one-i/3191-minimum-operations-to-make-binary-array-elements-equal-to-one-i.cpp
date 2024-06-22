class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        vector<int> flip(n, 0);
        int ans = 0;
        int cnt = 0;

        for (int i = 0; i < n; i++) {
            if (i >= 3) cnt -= flip[i - 3];
            
            if ((nums[i] + cnt) % 2 == 0){
                if (i + 2 >= n) return -1;
                ans++;
                cnt++;
                flip[i] = 1;
            }
        }
        return ans;
    }
};