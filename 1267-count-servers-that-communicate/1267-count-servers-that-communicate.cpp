class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();

        vector<int> colServerCount(n, 0);
        vector<int> rowAloneServerCount(m, -1);

        int res = 0;

        for(int row = 0; row < m; row++) {
            int countServerRow = 0;
            for(int col = 0; col < n; col++) {
                if(grid[row][col] == 1) {
                    countServerRow += 1;
                    colServerCount[col]++;
                    rowAloneServerCount[row] = col;
                }
            }

            if(countServerRow > 1) {
                res += countServerRow;
                rowAloneServerCount[row] = -1;
            }
        }

        for(int row = 0; row < m; row++) {
            if(rowAloneServerCount[row] != -1) {
                int col = rowAloneServerCount[row];
                if(colServerCount[col] > 1) {
                    res += 1;
                }
            }
        }

        return res;
    }
};