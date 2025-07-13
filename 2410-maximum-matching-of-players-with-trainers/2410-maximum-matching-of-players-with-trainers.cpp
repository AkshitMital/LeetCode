class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        sort(players.begin(), players.end());
        sort(trainers.begin(), trainers.end());

        int i = 0, j = 0, n = players.size(), m = trainers.size();

        int res = 0;
        for(; i < n && j < m; i++) {
            while(j < m && players[i] > trainers[j]) {
                j++;
            }
            if(j < m) {
                res++;
                j++;
            }
        }

        return res;
    }
};