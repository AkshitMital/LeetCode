class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        int m = heightMap.size(), n = heightMap[0].size();

        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        vector<vector<bool>> vis(m, vector<bool>(n, false));
        vector<vector<int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

        for(int r = 0; r < m; r++) {
            for(int c : {0, n - 1}) {
                pq.push({heightMap[r][c], {r, c}});
                vis[r][c] = true;
            }
        }

        for(int c = 0; c < n; c++) {
            for(int r : {0, m - 1}) {
                pq.push({heightMap[r][c], {r, c}});
                vis[r][c] = true;
            }
        }

        int trappedWater = 0;

        while(!pq.empty()) {
            auto [height, cell] = pq.top();
            pq.pop();

            int row = cell.first;
            int col = cell.second;

            for(auto& dir : directions) {
                int nrow = row + dir[0];
                int ncol = col + dir[1];

                if(nrow >= 0 && ncol >= 0 && nrow < m && ncol < n && !vis[nrow][ncol]) {
                    trappedWater += max(0, height - heightMap[nrow][ncol]);
                    pq.push({max(height, heightMap[nrow][ncol]), {nrow, ncol}});
                    vis[nrow][ncol] = true;
                }
            }
        }

        return trappedWater;
    }
};