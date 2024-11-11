class Solution {
public:
    bool primeSubOperation(vector<int>& nums) {
        int n = *max_element(nums.begin(), nums.end());
        vector<int> primes(n+1, 1);
        primes[0] = 0;
        primes[1] = 0;
        for(int i = 2; i*i <= n; i++){
            if(primes[i] == 1){
                for(int j = i*i; j <= n; j += i){
                    primes[j] = 0;
                }
            }
        }

        for(int i = nums.size()-2; i >= 0; i--){
            if(nums[i] >= nums[i+1]){
                for(int j = 2; j < nums[i]; j++){
                    if(primes[j] == 1 && nums[i] - j < nums[i+1]){
                        nums[i] -= j;
                        break;
                    }
                }

                if(nums[i] >= nums[i+1]) return false;
            }
        }

        return true;
    }
};