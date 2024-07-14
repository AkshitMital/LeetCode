class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int,int> > adj[n];
        for(int i=0; i<flights.size(); i++){
            int u = flights[i][0];
            int v = flights[i][1];
            int wt = flights[i][2];

            adj[u].push_back({v,wt});
        }

        queue<pair<int,pair<int,int> > >q;
        vector<int> short_dist(n, INT_MAX);

        short_dist[src] = 0;
        q.push({0,{src,0}});

        while(!q.empty()){
            int stop = q.front().first;
            int node = q.front().second.first;
            int dist = q.front().second.second;
            q.pop();
            if(stop > k){
                continue;
            }

            for(auto it : adj[node]){
                int wt = it.second;
                int v = it.first;

                if(wt + dist < short_dist[v] && stop<=k){
                    short_dist[v] = wt + dist;
                    q.push({stop+1,{v,short_dist[v]}});
                }
            }
        }
        if(short_dist[dst] == INT_MAX)
            return -1;

        return short_dist[dst];
    }
};