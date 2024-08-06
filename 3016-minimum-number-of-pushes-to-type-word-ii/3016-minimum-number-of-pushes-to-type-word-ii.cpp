class Solution {
public:
    int minimumPushes(string word) {
        unordered_map<char, int> freq;
        for(auto ch : word) freq[ch]++;

        priority_queue<int> pq;
        for(auto it : freq) pq.push(it.second);
        int ans = 0;
        int idx = 0;

        while(!pq.empty()){
            int num = pq.top();
            pq.pop();
            ans += ((1 + idx/8) * num);
            idx++;
        }

        return ans;
    }
};