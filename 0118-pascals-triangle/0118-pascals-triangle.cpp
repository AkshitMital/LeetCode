class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        for(int i = 0; i < numRows; i++) {
            vector<int> row(i + 1, 1);
            for(int j = 0; j <= i; j++) {
                if(i == 0 || j == 0 || j == i) continue;
                row[j] = res[i - 1][j] + res[i - 1][j - 1];
            }
            res.push_back(row);
        }

        return res;
    }
};