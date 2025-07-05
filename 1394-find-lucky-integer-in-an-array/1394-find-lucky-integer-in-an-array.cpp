class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int,int> mpp;
        for(int& num : arr) mpp[num]++;

        int ans = -1;
        for(auto [num, freq] : mpp) {
            if(num == freq) ans = max(ans, num);
        }

        return ans;
    }
};