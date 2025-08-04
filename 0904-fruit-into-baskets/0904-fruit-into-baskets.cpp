class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int i = 0, j = 0, n = fruits.size(), res = 0;
        unordered_map<int, int> mpp;
        for(int j = 0; j < n; j++) {
            mpp[fruits[j]]++;

            while(i < j && mpp.size() > 2) {
                mpp[fruits[i]]--;
                if(mpp[fruits[i]] == 0) mpp.erase(fruits[i]);
                i++;
            }

            res = max(res, j - i + 1);
        }

        return res;
    }
};