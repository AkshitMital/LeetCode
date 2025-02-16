class Solution {
private:
    bool solve(int idx, int n, vector<int>& result, vector<bool>& used) {
        if(idx >= result.size()) return true;

        if(result[idx] != -1) return solve(idx + 1, n, result, used);

        for(int num = n; num >= 1; num--) {
            if(used[num]) continue;

            used[num] = true;
            result[idx] = num;

            if(num == 1) {
                if(solve(idx + 1, n, result, used) == true) return true;

            } else {
                int nidx = idx + num;
                if(nidx < result.size() && result[nidx] == -1) {
                    result[nidx] = num;
                    if(solve(idx + 1, n, result, used) == true) return true;
                    result[nidx] = -1;
                }
            }

            used[num] = false;
            result[idx] = -1;
        }

        return false;
    }
public:
    vector<int> constructDistancedSequence(int n) {
        vector<int> result(2*n - 1, -1);
        vector<bool> used(n + 1, false);

        solve(0, n, result, used);

        return result;
    }
};