class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int, int> mpp;

        for(int& ans : answers) {
            mpp[ans]++;
        }

        int res = 0;

        for(auto [color, cnt] : mpp) {
            int groupSize = color + 1;
            int groups = ceil((double) cnt / groupSize);

            res += groups * groupSize;
        }

        return res;
    }
};