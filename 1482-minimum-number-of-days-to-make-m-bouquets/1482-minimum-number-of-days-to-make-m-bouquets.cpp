class Solution {
private:
    bool solve(int ind, vector<int>& bloomDay, int m, int k){
        int bouquets = 0;
        int consec = 0;
        for(int i = 0; i < bloomDay.size(); i++){
            if(bloomDay[i] <= ind) consec++;
            else consec = 0;

            if(consec == k){
                bouquets++;
                consec = 0;
            }
        }

        return (bouquets >= m);
    }
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int start = 0;
        int end = *max_element(bloomDay.begin(), bloomDay.end());
        int ans = -1;

        while(start <= end){
            int mid = start + (end-start)/2;
            if(solve(mid, bloomDay, m, k)){
                ans = mid;
                end = mid-1;
            }else{
                start = mid + 1;
            }
        }

        return ans;
    }
};