class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        map<int,int> mpp;
        for(int num : arr1) mpp[num]++;

        vector<int> ans;

        for(int i = 0; i < arr2.size(); i++){
            while(mpp[arr2[i]]){
                ans.push_back(arr2[i]);
                mpp[arr2[i]]--;
            }
            mpp.erase(arr2[i]);
        }

        for(auto it = mpp.begin(); it != mpp.end(); ++it){
            while(it->second > 0){
                ans.push_back(it->first);
                it->second--;
            }
        }

        return ans;
    }
};
