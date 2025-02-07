class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        unordered_map<int, int> ball2color;
        unordered_map<int, int> color2count;
        vector<int> res;

        for(auto& query : queries) {
            int ball = query[0];
            int color = query[1];

            if(ball2color.find(ball) != ball2color.end()) {
                int prevColor = ball2color[ball];
                ball2color[ball] = color;
                color2count[color]++;
                color2count[prevColor]--;
                if(color2count[prevColor] == 0) color2count.erase(prevColor);
            } else {
                ball2color[ball] = color;
                color2count[color]++;
            }

            res.push_back(color2count.size());
        }

        return res;
    }
};