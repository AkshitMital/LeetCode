class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        vector<int> first = edges[0];
        vector<int> second = edges[1];
        
        return (first[0]==second[0] || first[0]==second[1]) ? first[0] : first[1];
    }
};