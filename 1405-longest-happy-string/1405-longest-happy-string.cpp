class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        string ans = "";
        priority_queue<pair<int,char>> pq;

        if(a > 0) pq.push({a, 'a'});
        if(b > 0) pq.push({b, 'b'});
        if(c > 0) pq.push({c, 'c'});

        while(!pq.empty()){
            auto [currCnt, currCh] = pq.top();
            pq.pop();

            if(ans.length() >= 2 && ans[ans.length()-1] == currCh && ans[ans.length()-2] == currCh){
                if(pq.empty()) break;

                auto [nextCnt, nextCh] = pq.top();
                pq.pop();
                nextCnt--;
                ans.push_back(nextCh);

                if(nextCnt > 0) pq.push({nextCnt, nextCh});
            }
            
            currCnt--;
            ans.push_back(currCh);
            if(currCnt > 0) pq.push({currCnt, currCh});
        }

        return ans;
    }
};