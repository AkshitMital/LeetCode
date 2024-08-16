class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int m = arrays.size(), n = arrays[0].size();
        vector<pair<int,int>> maxi;
        vector<pair<int,int>> mini;
        for(int i = 0; i < m; i++){
            maxi.push_back({arrays[i].back(), i});
            mini.push_back({arrays[i].front(), i});
        }

        sort(maxi.begin(), maxi.end(), greater<pair<int,int>>());
        sort(mini.begin(), mini.end());

        if(maxi[0].second == mini[0].second) {
            int option1 = abs(maxi[0].first - mini[1].first);
            int option2 = abs(maxi[1].first - mini[0].first);
            return max(option1, option2);
        }

        return abs(maxi[0].first - mini[0].first);
    }
};