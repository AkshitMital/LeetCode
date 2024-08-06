class Solution {
public:
    int minimumPushes(string word) {
        unordered_map<char, int> freq;
        for(auto ch : word) freq[ch]++;

        priority_queue<pair<int,char>> pq;
        for(auto it : freq) pq.push({it.second, it.first});
        int ans = 0;
        int mul = 1;
        int temp = 2;
        
        while(!pq.empty()){
            char ch = pq.top().second;
            int num = pq.top().first;
            pq.pop();
            ans += (num * mul);
            temp++;
            if(temp > 9){
                temp = 2;
                mul++;
            }
        }

        return ans;
    }
};