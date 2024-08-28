class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        int max_points = 0;
        for(int i = 0; i < n-1; i++){
            map<double, int> slope_freq;
            for(int j = i + 1; j < n; j++){
                auto p1 = points[i];
                auto p2 = points[j];

                double slope = 0.0;
                if(p1[0] != p2[0]){
                    slope = double(abs(p2[1] - p1[1]))/double(abs(p2[0] - p1[0]));
                    slope_freq[slope]++;
                }
            }
            int temp = 0;
            for(auto [slope, freq] : slope_freq) temp = max(temp, freq+1);
            max_points = max(temp, max_points);
        }

        return max_points;
    }
};