class Solution {
public:
    int countGoodTriplets(vector<int>& arr, int a, int b, int c) {
        int n = arr.size();
        int ans = 0;
        for(int i = 0; i < n - 2; i++) {
            for(int j = i + 1; j < n - 1; j++) {
                for(int k = j + 1; k < n; k++) {
                    if(abs(arr[i] - arr[j]) > a) continue;
                    else if(abs(arr[j] - arr[k]) > b) continue;
                    else if(abs(arr[i] - arr[k]) > c) continue;
                    else {
                        ans++;
                    }
                }
            }
        }

        return ans;
    }
};