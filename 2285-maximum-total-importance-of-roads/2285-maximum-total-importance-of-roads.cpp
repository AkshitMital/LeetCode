class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        long long ans = 0;
        vector<long long> degree(n,0);
        
        for(auto& it : roads){
            degree[it[0]]++;
            degree[it[1]]++;
        }

        sort(degree.begin(), degree.end());

        for(int i = 0; i < n; i++){
            ans += degree[i]*(i+1);
        }

        return ans;
    }
};