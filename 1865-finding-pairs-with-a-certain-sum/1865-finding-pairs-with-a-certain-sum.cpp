class FindSumPairs {
private:
    vector<int> arr2;
    unordered_map<int, int> mpp1;
    int n;
public:
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        n = nums2.size();
        arr2 = nums2;
        for(int i = 0; i < nums1.size(); i++) {
            mpp1[nums1[i]]++;
        }
    }
    
    void add(int index, int val) {
        arr2[index] += val;
    }
    
    int count(int tot) {
        int pairs = 0;

        for(int i = 0; i < n; i++) {
            int diff = tot - arr2[i];
            if(mpp1.find(diff) != mpp1.end()) pairs += mpp1[diff];
        }

        return pairs;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */