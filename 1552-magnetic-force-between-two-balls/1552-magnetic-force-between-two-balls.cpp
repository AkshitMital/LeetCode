class Solution {
private:
    bool solve(int dist, vector<int>& position, int m){
        int prev = position[0];
        int count = 1;

        for(int i = 1; i < position.size(); i++){
            int curr = position[i];
            if(curr - prev >= dist){
                count++;
                prev = curr;
            }

            if(count == m) return true;
        }

        return false;
    }
public:
    int maxDistance(vector<int>& position, int m) {
        int n = position.size();
        sort(position.begin(),position.end());
        int minF = 1;
        int maxF = position[n-1] - position[0];
        int result = 0;
        while(minF <= maxF){
            int mid = minF + (maxF - minF)/2;
            if(solve(mid, position, m)){
                result = mid;
                minF = mid + 1;
            }else{
                maxF = mid - 1;
            }
        }

        return result;
    }
};