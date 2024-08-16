// class Solution {
// public:
//     int maxDistance(vector<vector<int>>& arrays) {
//         int m = arrays.size(), n = arrays[0].size();
//         vector<pair<int,int>> maxi;
//         vector<pair<int,int>> mini;
//         for(int i = 0; i < m; i++){
//             maxi.push_back({arrays[i].back(), i});
//             mini.push_back({arrays[i].front(), i});
//         }

//         sort(maxi.begin(), maxi.end(), greater<pair<int,int>>());
//         sort(mini.begin(), mini.end());

//         if(maxi[0].second == mini[0].second) {
//             int option1 = abs(maxi[0].first - mini[1].first);
//             int option2 = abs(maxi[1].first - mini[0].first);
//             return max(option1, option2);
//         }

//         return abs(maxi[0].first - mini[0].first);
//     }
// };

class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int m = arrays.size();
        int MAX = arrays[0].back();
        int MIN = arrays[0].front();
        int res = 0;
        for(int i = 1; i < m; i++){
            int currMax = arrays[i].back();
            int currMin = arrays[i].front();

            res = max({res, abs(currMax - MIN), abs(MAX - currMin)});

            MAX = max(MAX, currMax);
            MIN = min(MIN, currMin);
        }

        return res;
    }
};