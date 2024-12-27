class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int n = values.size();
        int maxLeftScore = values[0], maxScore = 0;

        for(int i = 1; i < n; i++){
            maxScore = max(maxScore, maxLeftScore + values[i] - i);
            maxLeftScore = max(maxLeftScore, values[i] + i);
        }

        return maxScore;
    }
};