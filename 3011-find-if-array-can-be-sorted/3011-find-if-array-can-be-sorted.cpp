class Solution {
private:
    int countSetBits(int num){
        int count = 0;

        while(num != 0){
            count += (num & 1);
            num = num >> 1;
        }

        return count;
    }
public:
    bool canSortArray(vector<int>& nums) {
        int n = nums.size();

        for(int i = n - 1; i >= 0; i--){
            bool didSwap = false;
            for(int j = 0; j <= i-1; j++){
                if(nums[j] > nums[j+1]){
                    if(countSetBits(nums[j]) == countSetBits(nums[j+1])){
                        swap(nums[j], nums[j+1]);
                        didSwap = true;
                    }
                    else return false;
                }
            }

            if(!didSwap) break;
        }

        return true;
    }
};