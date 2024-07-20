class Solution {
public:
    int minimumLength(string s) {
        int ans = 0;
        unordered_map<char, int> mpp;

        for (auto ch : s) mpp[ch]++;
        
        for (auto it : mpp) {
            if (it.second == 1 || it.second == 2) ans += it.second;
            else {
                if (it.second % 2 == 0) ans += 2;
                else ans += 1;
            }
        }

        return ans;
    }
};