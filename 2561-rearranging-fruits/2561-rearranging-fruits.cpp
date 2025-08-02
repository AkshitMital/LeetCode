class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        int minEl = INT_MAX;
        unordered_map<int, int> freq;

        for(int& fruit : basket1) {
            freq[fruit]++;
            minEl = min(minEl, fruit);
        }
        for(int& fruit : basket2) {
            freq[fruit]--;
            minEl = min(minEl, fruit);
        }
        
        vector<int> finalList;
        for(auto [cost, cnt] : freq) {
            if(cnt == 0) continue;
            if(cnt % 2 != 0) return -1;

            for(int c = 1; c <= abs(cnt)/2; c++) {
                finalList.push_back(cost);
            }
        }

        sort(finalList.begin(), finalList.end());

        long long result = 0;
        for(int i = 0; i < finalList.size() / 2; i++) {
            result += min(finalList[i], 2 * minEl);
        }

        return result;
    }
};