class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        int ind = 0, j = 0, sz = original.size();
        if(m*n != sz) return {};
        vector<vector<int>> ans(m, vector<int>(n, 0));
        while(ind < sz){
            int i = ind/n;
            ans[i][j] = original[ind];
            j++;
            if(j == n) j = 0;
            ind++;
        }

        return ans;
    }
};