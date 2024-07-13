class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double sum = 0.0;
        for(int i = 0; i < k; i++){
            sum += nums[i];
        }

        double ans = sum/k;
        int i = 0, j = k;

        while(j < nums.size()){
            sum += (nums[j++]);
            sum -= (nums[i++]);
            ans = max(ans, sum/k);
        }

        return ans;
    }
};