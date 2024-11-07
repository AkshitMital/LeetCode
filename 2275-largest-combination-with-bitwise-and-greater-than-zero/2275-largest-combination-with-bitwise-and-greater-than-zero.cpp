class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        vector<int> bitCount(24, 0);
        for(int candidate : candidates){
            int i = 0;
            while(candidate != 0){
                int bit = candidate & 1;
                candidate = candidate >> 1;
                bitCount[i] = (bit == 1) ? bitCount[i] + 1 : bitCount[i];
                i++;
            }
        }

        int res = *max_element(bitCount.begin(), bitCount.end());

        return res;
    }
};