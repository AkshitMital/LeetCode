// // class Solution {
// // private:
// //     long long solve(int row, int col, vector<vector<int>>& points, vector<vector<int>>& dp, int& m, int& n){
// //         if (row == 0) {
// //             long long maxi = 0;
// //             for (int i = 0; i < n; i++) {
// //                 long long x = points[row][i];
// //                 if (col != n) x -= abs(col - i);
// //                 maxi = max(maxi, x);
// //             }
// //             return maxi;
// //         }

// //         if(dp[row][col] != -1) return dp[row][col];

// //         long long maxi = 0;
// //         for(int i = 0; i < n; i++){
// //             long long x = points[row][i] + solve(row - 1, i, points, dp, m, n);
// //             if(col != n) x -= abs(col - i);
// //             maxi = max(maxi, x);
// //         }

// //         return dp[row][col] = maxi;
// //     }
// // public:
// //     long long maxPoints(vector<vector<int>>& points) {
// //         int m = points.size();
// //         int n = points[0].size();
// //         vector<vector<int>> dp(m, vector<int>(n+1, -1));
// //         return solve(m-1, n, points, dp, m, n);
// //     }
// // };

// class Solution {
// public:
//     long long maxPoints(vector<vector<int>>& points) {
//         int m = points.size();
//         int n = points[0].size();
//         vector<vector<long long>> dp(m, vector<long long>(n, 0));

//         for (int col = 0; col < n; col++) {
//             dp[0][col] = points[0][col];
//         }

//         for (int row = 1; row < m; row++) {
//             for (int col = 0; col < n; col++) {
//                 long long maxi = LLONG_MIN;
//                 for (int i = 0; i < n; i++) {
//                     maxi = max(maxi, dp[row-1][i] - abs(col - i));
//                 }
//                 dp[row][col] = points[row][col] + maxi;
//             }
//         }

//         return *max_element(dp[m-1].begin(), dp[m-1].end());
//     }
// };


// class Solution {
// private:
//     long long solve(int row, int col, vector<vector<int>>& points, vector<vector<int>>& dp, int& m, int& n){
//         if (row == 0) {
//             long long maxi = 0;
//             for (int i = 0; i < n; i++) {
//                 long long x = points[row][i];
//                 if (col != n) x -= abs(col - i);
//                 maxi = max(maxi, x);
//             }
//             return maxi;
//         }

//         if(dp[row][col] != -1) return dp[row][col];

//         long long maxi = 0;
//         for(int i = 0; i < n; i++){
//             long long x = points[row][i] + solve(row - 1, i, points, dp, m, n);
//             if(col != n) x -= abs(col - i);
//             maxi = max(maxi, x);
//         }

//         return dp[row][col] = maxi;
//     }
// public:
//     long long maxPoints(vector<vector<int>>& points) {
//         int m = points.size();
//         int n = points[0].size();
//         vector<vector<int>> dp(m, vector<int>(n+1, -1));
//         return solve(m-1, n, points, dp, m, n);
//     }
// };

// class Solution {
// public:
//     long long maxPoints(vector<vector<int>>& points) {
//         int m = points.size();
//         int n = points[0].size();
//         vector<long long> prev(n, 0), curr(n, 0);

//         for (int col = 0; col < n; col++) {
//             prev[col] = points[0][col];
//         }

//         for (int row = 1; row < m; row++) {
//             for (int col = 0; col < n; col++) {
//                 long long maxi = LLONG_MIN;
//                 for (int i = 0; i < n; i++) {
//                     maxi = max(maxi, prev[i] - abs(col - i));
//                 }
//                 curr[col] = points[row][col] + maxi;
//             }
//             prev = curr;
//         }

//         return *max_element(prev.begin(), prev.end());
//     }
// };

class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
        int m = points.size();
        int n = points[0].size();
        vector<long long> prev(n, 0), curr(n, 0);

        for (int col = 0; col < n; col++) {
            prev[col] = points[0][col];
        }

        for (int row = 1; row < m; row++) {
            vector<long long> left(n, 0), right(n, 0);
            left[0] = prev[0];
            for(int col = 1; col < n; col++){
                left[col] = max(left[col - 1] - 1, prev[col]);
            }
            right[n-1] = prev[n-1];
            for(int col = n-2; col >= 0; col--){
                right[col] = max(right[col + 1] - 1, prev[col]);
            }

            for(int col = 0; col < n; col++){
                curr[col] = points[row][col] + max(left[col], right[col]);
            }

            prev = curr;
        }

        return *max_element(prev.begin(), prev.end());
    }
};
