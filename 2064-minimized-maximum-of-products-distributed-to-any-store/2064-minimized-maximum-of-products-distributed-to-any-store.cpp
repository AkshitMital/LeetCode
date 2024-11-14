class Solution {
private:
    bool isPossible(int n, vector<int>& quantities, int x){
        int cnt = 0;

        for (int& quantity : quantities) {
            cnt += (quantity + x - 1) / x;
        }

        return cnt <= n;
    }
public:
    int minimizedMaximum(int n, vector<int>& quantities) {
        int r = *max_element(quantities.begin(), quantities.end());
        int ans = r, l = 1;

        while(l <= r){
            int mid = l + (r - l) / 2; 
            if(isPossible(n, quantities, mid)){
                ans = mid;
                r = mid-1;
            }
            else l = mid + 1;
        }

        return ans;
    }
};