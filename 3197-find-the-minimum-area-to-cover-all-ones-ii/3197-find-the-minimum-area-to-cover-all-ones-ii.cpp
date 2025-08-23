class Solution {
public:
    int minArea(int startRow, int endRow, int startCol, int endCol, vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int minRow = m, maxRow = 0, minCol = n, maxCol = 0;
        for(int i = startRow; i < endRow; i++) {
            for(int j = startCol; j < endCol; j++) {
                if(grid[i][j] == 1) {
                    minRow = min(minRow, i);
                    maxRow = max(maxRow, i);
                    minCol = min(minCol, j);
                    maxCol = max(maxCol, j);
                }
            }
        }

        return (maxRow - minRow + 1) * (maxCol - minCol + 1);
    }

    int solve(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();

        int res = INT_MAX;

        for(int rowSplit = 1; rowSplit < m; rowSplit++) {
            for(int colSplit = 1; colSplit < n; colSplit++) {
                int top = minArea(0, rowSplit, 0, n, grid);
                int bottomLeft = minArea(rowSplit, m, 0, colSplit, grid);
                int bottomRight = minArea(rowSplit, m, colSplit, n, grid);

                res = min(res, top + bottomLeft + bottomRight);

                int topLeft = minArea(0, rowSplit, 0, colSplit, grid);
                int topRight = minArea(0, rowSplit, colSplit, n, grid);
                int bottom = minArea(rowSplit, m, 0, n, grid);

                res = min(res, topRight + topLeft + bottom);
            }
        }

        for(int split1 = 1; split1 < m; split1++) {
            for(int split2 = split1 + 1; split2 < m; split2++) {
                int top = minArea(0, split1, 0, n, grid);
                int middle = minArea(split1, split2, 0, n, grid);
                int bottom = minArea(split2, m, 0, n, grid);

                res = min(res, top + middle + bottom);
            }
        }

        return res;
    }

    vector<vector<int>> rotateClockwise(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> rotateGrid(n, vector<int>(m, 0));

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                rotateGrid[j][m - i - 1] = grid[i][j];
            }
        }

        return rotateGrid;
    }

    int minimumSum(vector<vector<int>>& grid) {
        int result = solve(grid);

        vector<vector<int>> rotateGrid = rotateClockwise(grid);

        result = min(result, solve(rotateGrid));

        return result;
    }
};