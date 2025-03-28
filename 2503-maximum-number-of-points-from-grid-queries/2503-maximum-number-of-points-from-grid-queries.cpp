class Solution {
public:
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        int Q = queries.size();
        int m = grid.size();
        int n = grid[0].size();
        vector<int> res(Q, 0);
        vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};

        vector<pair<int, int>> sortedQ;
        for(int i = 0; i < Q; i++) {
            sortedQ.push_back({queries[i], i});
        }

        sort(begin(sortedQ), end(sortedQ));

        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        pq.push({grid[0][0], 0, 0});
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        visited[0][0] = true;
        int points = 0;

        for(int i = 0; i < Q; i++) {
            int queryVal = sortedQ[i].first;
            int idx = sortedQ[i].second;

            while(!pq.empty() && pq.top()[0] < queryVal) {
                int row = pq.top()[1];
                int col = pq.top()[2];
                pq.pop();
                points++;

                for(auto& dir : directions) {
                    int nrow = row + dir.first;
                    int ncol = col + dir.second;

                    if(nrow >= 0 && ncol >= 0 && nrow < m && ncol < n && !visited[nrow][ncol]) {
                        pq.push({grid[nrow][ncol], nrow, ncol});
                        visited[nrow][ncol] = true;
                    }
                }
            }

            res[idx] = points;
        }

        return res;
    }   
};