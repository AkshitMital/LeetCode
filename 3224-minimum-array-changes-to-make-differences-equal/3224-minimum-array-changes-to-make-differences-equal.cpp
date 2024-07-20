class Solution {
private:

    int findMinChanges(unordered_map<int, vector<int>>& mpp, vector<int>& vec, int n) {
        int mini = n;

        for (auto it : mpp) {
            auto diff = it.first;
            auto values = it.second;
            int pos = lower_bound(vec.begin(), vec.end(), diff) - vec.begin();
            int changes = pos * 2 + (n / 2 - pos);

            for (int value : values) changes -= (value < diff) ? 2 : 1;
            
            mini = min(mini, changes);
        }

        return mini;
    }
public:
    int minChanges(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, vector<int>> mpp;

        for (int i = 0; i<n / 2; i++) {
            int num1 = nums[i];
            int num2 = nums[n-i-1];
            int diff = abs(num1-num2);
            int maxi = max(max(num1, num2), max(k - num1, k - num2));
            mpp[diff].push_back(maxi);
        }
        
        vector<int> vec;

        for (auto it : mpp) {
            auto key = it.first;
            auto values = it.second;
            vec.insert(vec.end(), values.begin(), values.end());
        }

        sort(vec.begin(), vec.end());
        return findMinChanges(mpp, vec, n);
    }
};
