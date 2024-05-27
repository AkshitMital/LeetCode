class Solution {
public:
    int specialArray(vector<int>& nums) {
        int arr[1001]={0};
        for(int num: nums) arr[num]++;
        int total=nums.size();
        for(int i=0;i<1001;i++){
            if(i==total) 
                return i;
            total-=arr[i];
        }
        return -1;
    }
};