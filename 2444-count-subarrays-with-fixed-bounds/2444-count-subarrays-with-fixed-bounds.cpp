class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long ans = 0;
        long long minPos = -1 , maxPos = -1, culprit = -1;
        for(long long i=0; i<nums.size(); i++){
            if(nums[i] == minK){
                minPos = i;
            }
            if(nums[i] == maxK){
                maxPos = i;
            }
            if(nums[i] < minK || nums[i] > maxK){
                culprit = i;
            }
            long long smaller = min(minPos, maxPos);
            long long diff = smaller - culprit;
            if(diff<=0){
                ans += 0;
            }else{
                ans += diff;
            }
        }
        return ans;
    }
};