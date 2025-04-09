class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        for (int num : nums) {
            if(num < k) return -1;
        }
        
        int ans = 0;
        while(true){
            int maxi = *max_element(nums.begin(), nums.end());
            if(maxi == k) break;
            
            int h = k;
            for(int& x : nums){
                if(x < maxi && x > h) h = x;
            }
    
            for(int& num : nums){
                if(num > h) num = h;
            }
    
            ans++;
        }
    
        return ans;
    }
};