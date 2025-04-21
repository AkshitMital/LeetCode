class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        int maxVal = 0, minVal = 0, curr = 0;
        for(int& d : differences) {
            curr = curr + d;

            maxVal = max(maxVal, curr);
            minVal = min(minVal, curr);

            if((upper - maxVal) - (lower - minVal) + 1 <= 0) return 0;
        }

        return (upper - maxVal) - (lower - minVal) + 1;
    }
};