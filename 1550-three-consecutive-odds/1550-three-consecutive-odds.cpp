class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int temp = 3;
        for(int i = 0; i < arr.size(); i++){
            if(arr[i] % 2 == 0) temp = 3;
            else temp--;
            if(temp == 0) return true;
        }
        return false;
    }
};