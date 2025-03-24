class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());

        int res = 0;
        int start = 0;
        int end = 0;
        for(int i = 0; i < meetings.size(); i++) {
            if(meetings[i][0] > end) {
                res += (meetings[i][0] - end - 1);
            }
            end = max(end, meetings[i][1]);
        }

        if(end < days) res += (days - end);

        return res;
    }
};