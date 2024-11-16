class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> res;

        int consec = 1;
        for(int i = 1; i < k; i++){
            if(nums[i] == nums[i-1] + 1) consec++;
            else consec = 1;
        }
        if(consec >= k) res.push_back(nums[k-1]);
        else res.push_back(-1);

        int r = k;
        while(r < n){
            if(nums[r-1] + 1 != nums[r]) consec = 1;
            else consec++;

            if(consec >= k) res.push_back(nums[r]);
            else res.push_back(-1);

            r++;
        }

        return res;
    }
};