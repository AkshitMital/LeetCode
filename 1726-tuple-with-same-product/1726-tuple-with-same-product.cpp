class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        unordered_map<int,int> mpp;

        for(int i = 0; i < nums.size(); i++) {
            for(int j = i + 1; j < nums.size(); j++) {
                mpp[nums[i]*nums[j]]++;
            }
        }

        int res = 0;

        for(auto [product, freq] : mpp) {
            int tuple = ((freq * (freq - 1))/2);
            res += (tuple * 8);
        }

        return res;
    }
};