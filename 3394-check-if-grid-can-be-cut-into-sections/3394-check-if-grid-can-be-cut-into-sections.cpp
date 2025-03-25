class Solution {
private:
    bool merge(int n, vector<vector<int>>& axis) {
        sort(axis.begin(), axis.end());
        vector<vector<int>> res;

        res.push_back(axis[0]);

        for(int i = 1; i < axis.size(); i++) {
            if(axis[i][0] < res.back()[1]) {
                res.back()[1] = max(res.back()[1], axis[i][1]);
            } else {
                res.push_back(axis[i]);
            }

            if(res.size() >= 3) return true;
        }

        return false;
    }
public:
    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        vector<vector<int>> x_axis;
        vector<vector<int>> y_axis;

        for(auto& rectangle : rectangles) {
            x_axis.push_back({rectangle[0], rectangle[2]});
            y_axis.push_back({rectangle[1], rectangle[3]});
        }

        if(merge(n, x_axis) || merge(n, y_axis)) return true;

        return false;
    }
};