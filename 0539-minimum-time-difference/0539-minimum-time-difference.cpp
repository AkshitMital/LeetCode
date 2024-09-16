class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        vector<bool> minutes(24*60, false);
        for(string time: timePoints){
            int hrs = stoi(time.substr(0, 2));
            int min = stoi(time.substr(3));

            int mins = hrs*60 + min;
            if(minutes[mins]) return 0;
            minutes[mins] = true;
        }

        int prevIdx = INT_MAX;
        int firstIdx = INT_MAX;
        int lastIdx = INT_MAX;
        int ans = INT_MAX;

        for(int i = 0; i < 24*60; i++){
            if(minutes[i]){
                if(prevIdx != INT_MAX) ans = min(ans, i - prevIdx);
                prevIdx = i;
                if(firstIdx == INT_MAX) firstIdx = i;
                lastIdx = i;
            }
        }

        return min(ans, 24*60 - lastIdx + firstIdx);
    }
};