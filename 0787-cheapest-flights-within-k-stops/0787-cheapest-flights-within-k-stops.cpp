class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int,int>> adj[n];
        for(auto it : flights){
            adj[it[0]].push_back({it[1],it[2]});
        }
        vector<int> dist(n, 1e9);
        dist[src] = 0;
        queue<pair<int,pair<int,int>>> q;
        q.push({k,{src,0}});
        while(!q.empty()){
            auto it = q.front();
            int stops = it.first;
            int node = it.second.first;
            int prev_dis = it.second.second;
            q.pop();
            if(stops < 0) continue;
            for(auto i : adj[node]){
                int adjNode = i.first;
                int wt = i.second;
                if(prev_dis + wt < dist[adjNode] && stops >= 0){
                    dist[adjNode] = prev_dis + wt;
                    q.push({ stops-1, {adjNode, prev_dis + wt}});
                }
            }
        }
        return (dist[dst] == 1e9) ? -1 : dist[dst];
    }
};