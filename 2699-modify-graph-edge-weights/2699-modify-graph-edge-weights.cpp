typedef long long ll;

class Solution {
private:
    ll dijkstra(int n, vector<vector<int>>& edges, int source, int destination){
        vector<vector<pair<ll,ll>>> adj(n);
        for(vector<int>& edge : edges){
            if(edge[2] != -1){
                adj[edge[0]].push_back({edge[1],edge[2]});
                adj[edge[1]].push_back({edge[0],edge[2]});
            }
        }

        priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>>> pq;
        vector<ll> dist(n, INT_MAX);
        vector<bool> vis(n, false);
        dist[source] = 0;
        pq.push({0, source});

        while(!pq.empty()){
            ll wt = pq.top().first;
            ll node = pq.top().second;
            pq.pop();

            if(vis[node]) continue;

            vis[node] = true;

            for(auto& [adjNode, edgeWt] : adj[node]){
                if(wt + edgeWt < dist[adjNode]){
                    dist[adjNode] = wt + edgeWt;
                    pq.push({dist[adjNode], adjNode});
                }
            }
        }

        return dist[destination];
    }
public:
    vector<vector<int>> modifiedGraphEdges(int n, vector<vector<int>>& edges, int source, int destination, int target) {
        ll currShortestDist = dijkstra(n, edges, source, destination);

        if(currShortestDist < target) return {};

        bool matchedTarget = (currShortestDist == target);

        for(auto& edge : edges){
            if(edge[2] == -1){
                edge[2] = (matchedTarget == true) ? 2e9 : 1;

                if(matchedTarget != true){
                    ll newShortestDist = dijkstra(n, edges, source, destination);
                    if(newShortestDist <= target){
                        matchedTarget = true;
                        edge[2] += (target - newShortestDist);
                    }
                }
            }
        }

        if(matchedTarget == false) return {};
        return edges;
    }
};