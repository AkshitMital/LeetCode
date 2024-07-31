class Solution {
private:
    int solve(int ind, int remWidth, vector<vector<int>>& books, int& shelfWidth, int maxHt, vector<vector<int>>& dp) {
        if (ind == 0) return maxHt;
        if (dp[ind][remWidth] != -1) return dp[ind][remWidth];

        int bW = books[ind - 1][0];
        int bH = books[ind - 1][1];

        int keep = INT_MAX;
        if (bW <= remWidth) {
            keep = solve(ind - 1, remWidth - bW, books, shelfWidth, max(bH, maxHt), dp);
        }

        int skip = maxHt + solve(ind - 1, shelfWidth - bW, books, shelfWidth, bH, dp);

        return dp[ind][remWidth] = min(keep, skip);
    }

public:
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        int n = books.size();
        vector<vector<int>> dp(n + 1, vector<int>(shelfWidth + 1, -1));
        return solve(n, shelfWidth, books, shelfWidth, 0, dp);
    }
};