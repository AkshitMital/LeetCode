class Solution {
public:
    //Approach 1: Floyd Warshal Algorithm
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));

        for(auto it : edges){
            int u = it[0], v = it[1], wt = it[2];
            dist[u][v] = wt;
            dist[v][u] = wt;
        }

        for(int i = 0; i < n; i++) dist[i][i] = 0;

        for(int k = 0; k < n; k++){
            for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++){
                    if(dist[i][k] == INT_MAX || dist[k][j] == INT_MAX) continue;
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }

        int cityNo = -1;
        int cntCity = n;

        for(int city = 0; city < n; city++){
            int cnt = 0;
            for(int adjCity = 0; adjCity < n; adjCity++){
                if(dist[city][adjCity] <= distanceThreshold) cnt++;
            }

            if(cnt <= cntCity){
                cntCity = cnt;
                cityNo = city;
            }
        }

        return cityNo;
    }

    //Approach 2: Dijkstra Algorithm
    // int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
    //     vector<pair<int,int> > adj[n];
    //     for(auto it : edges){
    //         adj[it[0]].push_back({it[1],it[2]});
    //         adj[it[1]].push_back({it[0],it[2]});
    //     }
    //     priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    //     int cityNo = -1 ,cntCity=INT_MAX;

    //     for(int city = 0; city<n; city++){
    //         vector<int> short_dist(n, INT_MAX);
    //         short_dist[city] = 0;
    //         pq.push({0,city});

    //         while(!pq.empty()){
    //             int dist = pq.top().first;
    //             int node = pq.top().second;
    //             pq.pop();

    //             for(auto it : adj[node]){
    //                 int wt = it.second;
    //                 int adjNode = it.first;

    //                 if(dist + wt < short_dist[adjNode]){
    //                     short_dist[adjNode] = dist + wt;
    //                     pq.push({dist + wt, adjNode});
    //                 }
    //             }
    //         }
    //         int count = 0; 
    //         for(int adjCity = 0; adjCity<n; adjCity++){
    //             if(short_dist[adjCity] <= distanceThreshold) count++;
    //         }
    //         if(count <= cntCity){
    //             cntCity = count;
    //             cityNo = city;
    //         }
    //     }

    //     return cityNo;
    // }
};
        