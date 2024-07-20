class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> mpp;
        for(auto num : nums) mpp[num]++;
        for(auto it : mpp){
            if(it.second > nums.size()/2) return it.first;
        }
        return -1;
    }
};