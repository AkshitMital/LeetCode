class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();

        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq; // min-pq
        vector<vector<int>> res(m, vector<int>(n, INT_MAX));
        vector<vector<int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

        pq.push({0, 0, 0});
        res[0][0] = 0;

        while(!pq.empty()) {
            auto curr = pq.top();
            pq.pop();

            int cost = curr[0];
            int row = curr[1];
            int col = curr[2];

            if(res[row][col] < cost) continue;

            for(int i = 0; i < 4; i++) {
                int nrow = row + dir[i][0];
                int ncol = col + dir[i][1];
                if(nrow < 0 || nrow >= m || ncol < 0 || ncol >= n) continue;

                int ncost = cost + ((i != grid[row][col] - 1) ? 1 : 0);

                if(ncost < res[nrow][ncol]) {
                    res[nrow][ncol] = ncost;
                    pq.push({ncost, nrow, ncol});
                }
            }
        }

        return res[m-1][n-1];
    }
};