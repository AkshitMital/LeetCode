class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        unordered_map<int,int> mpp;
        for(int& num : arr) mpp[num]++;
        for(int& num : target){
            if(mpp[num] == 0) return false;
            mpp[num]--;
        }

        return true;
    }
};