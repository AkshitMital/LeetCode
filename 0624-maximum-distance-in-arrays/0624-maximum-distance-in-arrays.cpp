class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int m = arrays.size();
        vector<pair<int,int>> maxi;
        vector<pair<int,int>> mini;

        for(int i = 0; i < m; i++){
            maxi.push_back({arrays[i].back(), i}); // last element and index
            mini.push_back({arrays[i].front(), i}); // first element and index
        }

        // Sort by value, descending for maxi, ascending for mini
        sort(maxi.begin(), maxi.end(), greater<pair<int,int>>());
        sort(mini.begin(), mini.end());

        int i = 0, j = 0;
        while (maxi[i].second == mini[j].second) {
            int diff_max = abs(maxi[i].first - mini[j+1].first);
            int diff_min = abs(maxi[i+1].first - mini[j].first);
            if(diff_max >= diff_min && j + 1 < m) {
                j++;
            } else if(i + 1 < m) {
                i++;
            }
        }

        return abs(maxi[i].first - mini[j].first);
    }
};
