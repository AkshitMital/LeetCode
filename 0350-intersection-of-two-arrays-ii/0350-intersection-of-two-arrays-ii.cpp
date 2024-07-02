class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        unordered_map<int,int> mpp1;
        unordered_map<int,int> mpp2;
        for(int i = 0; i < nums1.size(); i++) mpp1[nums1[i]]++;
        for(int i = 0; i < nums2.size(); i++) mpp2[nums2[i]]++;

        for(int i = 0; i <= 1000; i++){
            if(mpp1.find(i) != mpp1.end() && mpp2.find(i)!=mpp2.end()){
                int iter = min(mpp1[i], mpp2[i]);
                while(iter--) ans.push_back(i);
            }
        }

        return ans;
    }
};