class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        int maxCharIndex = 25;  // 'z' - 'a' = 25
        vector<vector<long long>> dist(maxCharIndex + 1, vector<long long>(maxCharIndex + 1, LLONG_MAX));

        for (int i = 0; i <= maxCharIndex; ++i) {
            dist[i][i] = 0;
        }

        // Fill in the given costs
        for (int i = 0; i < original.size(); ++i) {
            int u = original[i] - 'a';
            int v = changed[i] - 'a';
            int wt = cost[i];
            dist[u][v] = min(dist[u][v], (long long)wt);
        }

        // Apply the Floyd-Warshall algorithm to find all-pairs shortest paths
        for (int k = 0; k <= maxCharIndex; ++k) {
            for (int i = 0; i <= maxCharIndex; ++i) {
                for (int j = 0; j <= maxCharIndex; ++j) {
                    if (dist[i][k] != LLONG_MAX && dist[k][j] != LLONG_MAX) {
                        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                    }
                }
            }
        }

        // Calculate the total cost to transform source to target
        long long ans = 0;
        for (int i = 0; i < source.length(); ++i) {
            int u = source[i] - 'a';
            int v = target[i] - 'a';
            if (dist[u][v] == LLONG_MAX) {
                return -1;  // If there's no valid path
            }
            ans += dist[u][v];
        }

        return ans;
    }
};
