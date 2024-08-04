class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<int> subset;
        for(int i = 0; i < nums.size(); i++){
            int temp = 0;
            for(int j = i; j < nums.size(); j++){
                temp += nums[j];
                subset.push_back(temp);
            }
        }

        sort(subset.begin(), subset.end());

        int ans = 0;
        for(int i = left-1; i < right; i++){
            ans += (subset[i]);
        }

        return ans;
    }
};