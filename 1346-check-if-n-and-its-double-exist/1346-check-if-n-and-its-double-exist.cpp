class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        int n = arr.size();
        unordered_set<int> mpp;
        for(int i = 0; i < n; i++){
            int num = arr[i];
            int doub = num * 2;
            int div = (num % 2 == 0) ? num / 2 : 0;

            if((mpp.find(doub) != mpp.end()) || (mpp.find(div) != mpp.end())) return true;

            mpp.insert(num);
        }

        return false;
    }
};