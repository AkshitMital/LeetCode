class Solution {
    struct comp{
        bool operator()(pair<char, int> &p1, pair<char, int>& p2){
            if(p1.first == p2.first) {
                return p1.second < p2.second;
            }

            return p1.first > p2.first;
        }
    };
public:
    string clearStars(string s) {
        int n = s.length();
        priority_queue<pair<char, int>, vector<pair<char, int>>, comp> pq;
        
        for(int i = 0; i < n; i++) {
            char ch = s[i];
            if(ch == '*') {
                int idx = pq.top().second;
                pq.pop();
                s[idx] = '*';
            } else {
                pq.push({ch, i});
            }
        }

        string ans = "";
        for(int i = 0; i < n; i++) {
            if(s[i] != '*') ans.push_back(s[i]);
        }

        return ans;
    }
};