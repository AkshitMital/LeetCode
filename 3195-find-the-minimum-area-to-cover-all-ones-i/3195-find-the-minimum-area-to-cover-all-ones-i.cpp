class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int startRow = m, startCol = n, endRow = 0, endCol = 0;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 1) {
                    startRow = min(startRow, i);
                    endRow = max(endRow, i);
                    startCol = min(startCol, j);
                    endCol = max(endCol, j);
                }
            }
        }

        // cout << "startRow: " << startRow << endl;
        // cout << "endRow: " << endRow << endl;
        // cout << "startCol: " << startCol << endl;
        // cout << "endCol: " << endCol << endl;

        return (endRow - startRow + 1) * (endCol - startCol + 1);
    }
};