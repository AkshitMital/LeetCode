class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<pair<int,int>> adj[n];
        for(auto it : roads){
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }
        priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<pair<long long,int>>> pq;
        vector<long long> short_dist(n,1e15);
        vector<int> ways(n,0);
        ways[0] = 1;
        short_dist[0] = 0;
        pq.push({0,0});
        int mod = 1e9 + 7;
        while(!pq.empty()){
            long long dist = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            if (node == n - 1) break;
            for(auto it : adj[node]){
                int adjNode = it.first;
                long long wt = it.second;

                if(dist + wt < short_dist[adjNode]){
                    short_dist[adjNode] = dist + wt;
                    pq.push({short_dist[adjNode],adjNode});
                    ways[adjNode] = ways[node];
                }
                else if(dist + wt == short_dist[adjNode]){
                    ways[adjNode] = (ways[adjNode] + ways[node] * 1LL ) % mod;
                }
            }
        }
        return ways[n-1];
    }
};