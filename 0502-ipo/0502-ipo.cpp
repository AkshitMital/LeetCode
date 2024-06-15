class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        vector<pair<int, int>> arr(profits.size());
        for(int i = 0; i < profits.size(); i++){
            arr[i] = {capital[i], profits[i]};
        }
        sort(arr.begin(), arr.end());

        priority_queue<int> pq;
        int i = 0;
        while(k--){
            while(i < profits.size() && arr[i].first <= w){
                pq.push(arr[i].second);
                i++;
            }

            w += pq.top();
            pq.pop();
        }

        return w;
    }
};