class Solution {
private:
    int findMaxPrice(vector<vector<int>>& items, int price){
        int l = 0;
        int r = items.size()-1;
        int mid;
        int maxBeauty = 0;

        while(l <= r){
            mid = l + (r-l)/2;

            if(items[mid][0] > price){
                r = mid - 1;
            }
            else{
                maxBeauty = max(maxBeauty, items[mid][1]);
                l = mid + 1;
            }
        }

        return maxBeauty;
    }
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        int n = items.size(), m = queries.size();
        vector<int> result(m, 0);
        sort(items.begin(), items.end());

        int maxVal = items[0][1];
        for(int i = 1; i < n; i++) {
            maxVal = max(maxVal, items[i][1]);
            items[i][1] = maxVal;
        }

        for(int i = 0; i < m; i++){
            int price = queries[i];
            result[i] = findMaxPrice(items, price);
        }

        return result;
    }
};