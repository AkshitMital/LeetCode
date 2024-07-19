class Solution {
public:
    int search(vector<int>& arr, int target) {
        int s = 0, e = arr.size()-1;

        while(s<=e){
            int mid = s + (e-s)/2;
            if(target <= arr[mid]){
                e = mid-1;
            }
            if(target > arr[mid]){
                s = mid+1;
            }
            if(target == arr[mid]) return mid;
        }

        return -1;
    }
};