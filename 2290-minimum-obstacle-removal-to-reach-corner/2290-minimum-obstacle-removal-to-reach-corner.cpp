class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> res(m, vector<int>(n, INT_MAX));
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

        res[0][0] = 0;
        pq.push({0, {0, 0}});

        while(!pq.empty()){
            auto curr = pq.top();
            pq.pop();
            int currRow = curr.second.first;
            int currWt = curr.first;
            int currCol = curr.second.second;

            for(auto dir : directions){
                int newRow = currRow + dir.first;
                int newCol = currCol + dir.second;

                if(newRow >= m || newCol >= n || newRow < 0 || newCol < 0) continue;

                int wt = (grid[newRow][newCol] == 1) ? 1 : 0;

                if(currWt + wt < res[newRow][newCol]){
                    res[newRow][newCol] = currWt + wt;
                    pq.push({currWt + wt, {newRow, newCol}});
                }
            }
        }

        return res[m-1][n-1];
    }
};