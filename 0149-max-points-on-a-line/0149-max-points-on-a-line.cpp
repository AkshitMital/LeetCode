// class Solution {
// public:
//     int maxPoints(vector<vector<int>>& points) {
//         int n = points.size();
//         if (n < 2) return n;
//         int max_points = 1;
//         for(int i = 0; i < n-1; i++){
//             unordered_map<double, int> slope_freq;
//             int verticals = 0;
//             int duplicates = 0;
//             for(int j = i + 1; j < n; j++){
//                 auto p1 = points[i];
//                 auto p2 = points[j];

//                 if (p1 == p2) duplicates++;
//                 else if(p1[0] == p2[0]) verticals++;
//                 else{
//                     double slope = double(p2[1] - p1[1])/double(p2[0] - p1[0]);
//                     slope_freq[slope]++;
//                 }

//             }
//             int temp = verticals;
//             for(auto [slope, freq] : slope_freq) temp = max(temp, freq);
//             max_points = max(max_points, temp + duplicates + 1);
//         }

//         return max_points;
//     }
// };

class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        unordered_map<double, int> slope_freq;
        int n = points.size();
        int max_points = 1;
        for(int i = 0; i < n-1; i++){
            for(int j = i + 1; j < n; j++){
                auto p1 = points[i];
                auto p2 = points[j];
                double dx = double(p2[0] - p1[0]), dy = double(p2[1] - p1[1]), slope;
                
                if(dx == 0) slope = INT_MAX;
                else slope = dy/dx;

                slope_freq[slope]++;
                max_points = max(max_points, slope_freq[slope] + 1);

            }
            slope_freq.clear();
        }

        return max_points;
    }
};