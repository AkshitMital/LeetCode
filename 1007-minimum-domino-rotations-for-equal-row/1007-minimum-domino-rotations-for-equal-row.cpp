class Solution {
private:
    int find(vector<int>& tops, vector<int>& bottoms, int& val) {
        int topSwap = 0, bottomSwap = 0;

        for(int i = 0; i < tops.size(); i++) {
            if(tops[i] != val && bottoms[i] != val) return -1;
            if(tops[i] == val && bottoms[i] == val) continue;
            if(tops[i] == val && bottoms[i] != val) bottomSwap++;
            if(tops[i] != val && bottoms[i] == val) topSwap++;
        }

        return min(bottomSwap, topSwap);
    }
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int result = INT_MAX;

        for(int val = 1; val <= 6; val++) {
            int swaps = find(tops, bottoms, val);

            if(swaps != -1) {
                result = min(result, swaps);
            }
        }

        return result == INT_MAX ? -1 : result;
    }
};