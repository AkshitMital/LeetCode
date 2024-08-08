class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        vector<vector<int>> ans;
        int delrow[4] = {0, 1, 0, -1};// East, South, West, North
        int delcol[4] = {1, 0, -1, 0};// East, South, West, North
        ans.push_back({rStart, cStart});
        int dir = 0, steps = 0;

        while(ans.size() < rows*cols){
            if(dir == 0 || dir == 2) steps++;
            for(int count = 0; count < steps; count++){
                rStart += delrow[dir];
                cStart += delcol[dir];

                if(rStart >= 0 && rStart < rows && cStart >= 0 && cStart < cols) ans.push_back({rStart, cStart});
            }
            dir = (dir + 1) % 4;
        }

        return ans;
    }
};