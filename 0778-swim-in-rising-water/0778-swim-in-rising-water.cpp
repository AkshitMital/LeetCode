class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int currentTime = grid[0][0];

        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> q;
        q.push({currentTime, 0, 0});

        while (!q.empty()) {
            int i = q.top()[1], j = q.top()[2];
            int time = q.top()[0];
            q.pop();

            if (grid[i][j] == -1) continue;
            grid[i][j] = -1; 

            currentTime = max(time, currentTime);
            if (i == m-1 && j == n-1) return currentTime;

            if (i > 0) q.push({grid[i-1][j], i-1, j});
            if (j > 0) q.push({grid[i][j-1], i, j-1});
            if (i < m-1) q.push({grid[i+1][j], i+1, j});
            if (j < n-1) q.push({grid[i][j+1], i, j+1});
        }

        return currentTime;

    }
};