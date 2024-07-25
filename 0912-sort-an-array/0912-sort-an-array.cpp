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

        if(nums.empty()) return nums;

        int low = 0;
        int high = nums.size()-1;

        mergeSort(nums, low, high);

        return nums;
    }
};

// class Solution {
// private:
//     int partition(vector<int>& nums, int low, int high)
//     {
//         int i = low, j = high, pivot = nums[low];
//         while(i < j){
//             while(i <= high-1 && nums[i] <= pivot) i++;
//             while(j >= low+1 && nums[j] > pivot) j--;

//             if(i < j) swap(nums[i], nums[j]);
//         }

//         swap(nums[j], nums[low]);

//         return j;
//     }

//     void QuickSort(vector<int>& nums, int low, int high)
//     {
//         if(low >= high) return;
//         int pindex = partition(nums,low,high);
//         QuickSort(nums,low,pindex-1);
//         QuickSort(nums,pindex+1,high);
//     }
// public:
//     vector<int> sortArray(vector<int>& nums) 
//     {
//         if(nums.empty()) return nums;
        
//         int low = 0;
//         int high = nums.size() - 1;

//         QuickSort(nums, low, high);

//         return nums;
//     }
// };