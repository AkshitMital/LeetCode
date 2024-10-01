class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        unordered_map<int,int> mpp;
        for(int num : arr){
            int remainder = (num % k + k) % k;
            mpp[remainder]++;
        }

        for(int i = 0; i <= k/2; i++){
            if (i == 0) {
                if (mpp[i] % 2 != 0) return false;
            } else if (i == k / 2 && k % 2 == 0) {
                if (mpp[i] % 2 != 0) return false;
            } else {
                if (mpp[i] != mpp[k - i]) return false;
            }
        }

        return true;
    }
};