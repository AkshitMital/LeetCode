// class Solution {
// public:
//     int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
//         unordered_map<int, vector<int>> adj;
//         for(auto it : edges){
//             int u = it[0];
//             int v = it[1];
//             adj[u].push_back(v);
//             adj[v].push_back(u);
//         }

//         vector<int> min_d1(n + 1, INT_MAX);
//         vector<int> min_d2(n + 1, INT_MAX);
//         priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
//         pq.push({0,1});
//         min_d1[1] = 0;

//         while(!pq.empty()){
//             auto [timePassed, node] = pq.top();
//             pq.pop();

//             if(node == n && min_d2[n] != INT_MAX) return min_d2[n];

//             int div = timePassed/change;
//             if(div % 2 == 1) timePassed = change * (div + 1);

//             for(auto& nbr : adj[node]){
//                 if(min_d1[nbr] > timePassed + time){
//                     min_d2[nbr] = min_d1[nbr];
//                     min_d1[nbr] = timePassed + time;
//                     pq.push({timePassed + time, nbr});
//                 }
//                 else if(min_d2[nbr] > timePassed + time && min_d1[nbr] != timePassed + time){
//                     min_d2[nbr] = timePassed + time;
//                     pq.push({timePassed + time, nbr});
//                 }
//             }
//         }

//         return -1;
//     }
// };

class Solution {
public:
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        unordered_map<int, vector<int>> adj;
        for(auto it : edges){
            int u = it[0];
            int v = it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> min_d1(n + 1, INT_MAX);
        vector<int> min_d2(n + 1, INT_MAX);
        queue<pair<int, int>> q;
        q.push({1,1}); //{node, freq}
        min_d1[1] = 0;

        while(!q.empty()){
            auto [node, freq] = q.front();
            q.pop();

            int timePassed = (freq==1) ? min_d1[node] : min_d2[node];

            if(node == n && min_d2[n] != INT_MAX) return min_d2[n];

            int div = timePassed/change;
            if(div % 2 == 1) timePassed = change * (div + 1);

            for(auto& nbr : adj[node]){
                if(min_d1[nbr] == INT_MAX){
                    min_d1[nbr] = timePassed + time;
                    q.push({nbr, 1});
                }
                else if(min_d2[nbr] == INT_MAX && min_d1[nbr] != timePassed + time){
                    min_d2[nbr] = timePassed + time;
                    q.push({nbr, 2});
                }
            }
        }

        return -1;
    }
};