class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int currDiagnol = 0;
        int ans = 0;

        for(auto& dimension : dimensions) {
            int length = dimension[0];
            int width = dimension[1];

            int newDiagnol = sqrt(length * length + width * width);

            if(newDiagnol > currDiagnol) {
                currDiagnol = newDiagnol;
                ans = length * width;
            } else if(newDiagnol == currDiagnol) {
                ans = max(ans, length * width);
            }
        }

        return ans;
    }
};