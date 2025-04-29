// class Solution {
// public:
//     long long countSubarrays(vector<int>& nums, int k) {
//         int n = nums.size();
//         int max_no = INT_MIN;
//         int l=0,r=0;
//         for(int i=0; i<n; i++){
//             max_no = max(nums[i], max_no);
//         }
//         int countMax = 0;
//         long long ans = 0;
//         while(r<n){
//             if(nums[r] == max_no){
//                 countMax++;
//             }

//             while(countMax >= k){
//                 ans += n - r;
//                 if(nums[l]==max_no){
//                     countMax--;
//                 }
//                 l++;
//             }

//             r++;
//         }

//         return ans;
//     }
// };
class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        int max_no = INT_MIN;
        int l=0,r=0;
        vector<int> indices;
        for(int i=0; i<n; i++){
            max_no = max(nums[i], max_no);
        }
        long long ans = 0;
        for(int i=0; i<n; i++){
            if(nums[i]==max_no){
                indices.push_back(i);
            }
            int size = indices.size();
            if(size>=k){
                ans = ans + indices[size-k] + 1;
            }
        }

        return ans;
    }
};