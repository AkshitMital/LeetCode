class Solution {
private:
    void moveOnXYPlane(int& x, int& y, pair<int,int>& dir, int command, set<pair<int,int>>& obset){

        while(command--){
            int dir_x = dir.first;
            int dir_y = dir.second;
            int nx = x + dir_x;
            int ny = y + dir_y;
            if(obset.find({nx,ny}) != obset.end()) return;
            x = nx;
            y = ny;
        }
    }
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        set<pair<int,int>> obset;
        for(auto obstacle : obstacles) obset.insert({obstacle[0], obstacle[1]});
        vector<pair<int,int>> dir = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int i = 0, x = 0, y = 0;
        int maxDist = 0;
        for(int& command : commands){
            if(command == -1){
                i = (i + 1) % 4;
            }
            else if(command == -2){
                i = (i + 3) % 4;
            }
            else{
                moveOnXYPlane(x, y, dir[i], command, obset);
                maxDist = max(maxDist, (x*x) + (y*y));
            }
        }

        return maxDist;
    }
};