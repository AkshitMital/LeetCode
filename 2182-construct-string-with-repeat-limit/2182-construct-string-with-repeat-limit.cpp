class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        unordered_map<char, int> mpp;
        for(char ch : s) mpp[ch]++;

        priority_queue<char> pq;
        for(auto [ch, freq] : mpp) pq.push(ch);

        string res;
        while(!pq.empty()){
            char currCh = pq.top();
            int freq = mpp[currCh];
            pq.pop();

            int use = min(freq, repeatLimit);
            res.append(use, currCh);
            mpp[currCh] -= use;

            if(pq.empty()) return res;

            if(mpp[currCh] > 0 && !pq.empty()){
                char nextCh = pq.top();
                pq.pop();

                res.push_back(nextCh);
                mpp[nextCh]--;

                if(mpp[nextCh] > 0) pq.push(nextCh);

                pq.push(currCh);
            }
        }
        
        return res;
    }
};