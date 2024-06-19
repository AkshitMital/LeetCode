class Solution {
private:
    bool solve(long long ind, vector<int>& bloomDay, int m, int k){
        long long bouquets = 0;
        long long consec = 0;
        for(long long i = 0; i < bloomDay.size(); i++){
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

        if(m > bloomDay.size() / k )return -1;

        long long start = 0;
        long long end = *max_element(bloomDay.begin(), bloomDay.end());
        long long ans = -1;

        while(start <= end){
            long long mid = start + (end-start)/2;
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