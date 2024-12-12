class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<int> pq;
        for(int gift : gifts) pq.push(gift);

        while(k > 0){
            int gift = pq.top();
            pq.pop();

            pq.push(sqrt(gift));
            k--;
        }

        long long sum = 0;
        while(!pq.empty()){
            sum += pq.top();
            pq.pop();
        }

        return sum;
    }
};