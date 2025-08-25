class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        vector<vector<int>> store(m + n - 1);

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                store[i + j].push_back(mat[i][j]);
            }
        }

        vector<int> ans;
        for(int i = 0; i < store.size(); i++) {
            if(i % 2 == 0) reverse(store[i].begin(), store[i].end());
            for(auto num : store[i]) ans.push_back(num);
        }

        return ans;
    }
};