class Solution {
public:
    int numberOfPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int ans = 0, div;
        for(auto val1:nums1)
        {
            for(auto val2:nums2)
            {
                if(val1 % (val2 * k) == 0) ans++;
            }
        }
        return ans;
    }
};