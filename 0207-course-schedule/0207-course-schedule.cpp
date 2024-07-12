// class Solution {
// private:
//     bool dfs(int node, vector<int>& vis, vector<int>& pathVis, vector<vector<int>> adj){
//         vis[node] = 1;
//         pathVis[node] = 1;
        
//         for(auto it : adj[node]){
//             if(!vis[it]){
//                 if(dfs(it,vis,pathVis,adj)) return true;
//             }
            
//             else if(pathVis[it])
//                 return true;
//         }

//         pathVis[node] = 0;
//         return false;
//     }
// public:
//     bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
//         vector<vector<int>> adj(numCourses);
//         for(auto it : prerequisites){
//             adj[it[1]].push_back(it[0]);
//         }

//         vector<int> vis(numCourses,0);
//         vector<int> pathVis(numCourses,0);

//         for(int i=0; i<numCourses; i++){
//             if(!vis[i]){
//                 if(dfs(i, vis, pathVis, adj)) return false;
//             }
//         }

//         return true;
//     }
// };

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for(auto it : prerequisites){
            adj[it[1]].push_back(it[0]);
        }

        vector<int> indegree(numCourses, 0);

        for(int i = 0; i < numCourses; i++){
            for(auto& it : adj[i]) indegree[it]++;
        }

        queue<int> q;

        for(int i = 0; i <numCourses; i++){
            if(indegree[i] == 0) q.push(i);
        }

        vector<int> topoSort;

        while(!q.empty()){
            int node = q.front();
            topoSort.push_back(node);
            q.pop();

            for(auto it : adj[node]){
                indegree[it]--;
                if(indegree[it] == 0) q.push(it);
            }
        }

        return (topoSort.size() == numCourses);
    }
};