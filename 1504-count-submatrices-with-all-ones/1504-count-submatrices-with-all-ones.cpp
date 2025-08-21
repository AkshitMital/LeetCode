class Solution {
private:
    int solve(vector<int> vec, int n) {
        int cnt = 0;
        int temp = 0;
        
        for(int i = 0; i < n; i++) {
            if(vec[i] == 0) temp = 0;
            else temp++;

            cnt += temp;
        }

        return cnt;
    }
public:
    int numSubmat(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        int res = 0;

        for(int start = 0; start < m; start++) {
            vector<int> vec(n, 1);
            for(int end = start; end < m; end++) {
                for(int col = 0; col < n; col++) {
                    vec[col] = vec[col] & mat[end][col];
                }

                res = res + solve(vec, n);
            }
        }

        return res;
    }
};