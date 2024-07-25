class Solution {
private:
    void Merge(vector<int>& nums, int low, int high, int mid)
    {
        vector<int> res;
        int left = low;
        int right = mid+1;

        while(left<=mid && right<=high){
            if(nums[left]<=nums[right]){
                res.push_back(nums[left]);
                left++;
            }else{
                res.push_back(nums[right]);
                right++;
            }
        }
        while(left<=mid){
            res.push_back(nums[left]);
            left++;
        }

        while(right<=high){
            res.push_back(nums[right]);
            right++;
        }

        for(int i=low; i<=high; i++){
            nums[i] = res[i-low];
        }
    }

    void mergeSort(vector<int>& nums, int low, int high)
    {
        if(low>=high) return;

        int mid = low + (high-low)/2;

        mergeSort(nums, low, mid);
        mergeSort(nums, mid+1, high);

        Merge(nums,low,high,mid);
    }
public:
    vector<int> sortArray(vector<int>& nums) {

        if(nums.empty()){
            return nums;
        }

        int low = 0;
        int high = nums.size()-1;

        mergeSort(nums, low, high);

        return nums;
    }
};