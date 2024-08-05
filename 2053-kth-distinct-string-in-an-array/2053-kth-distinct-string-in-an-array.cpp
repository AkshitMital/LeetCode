class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string, int> mpp;
        for(auto it : arr) mpp[it]++;


        for(auto it : arr){
            if(mpp[it] == 1) k--;
            if(k == 0){
                return it;
            }
        }

        return "";
    }
};