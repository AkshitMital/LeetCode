class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        vector<pair<int, pair<char, int>>> total;
        unordered_map<int, int> ids;
        for (int i = 0; i < positions.size(); i++) {
            ids[positions[i]] = i;
        }
        for (int i = 0; i < positions.size(); i++) {
            total.push_back({positions[i], {directions[i], healths[i]}});
        }
        vector<int> temp(positions.size(), 0);
        stack<pair<int, pair<char, int>>> st;
        sort(total.begin(), total.end());

        for (auto num : total) {
            int pos = num.first;
            char dir = num.second.first;
            int health = num.second.second;

            if (!st.empty() && dir == 'L' && st.top().second.first == 'R') {
                while (!st.empty() && dir == 'L' && st.top().second.first == 'R') {
                    auto top = st.top();
                    if (top.second.second < health) {
                        st.pop();
                        health--;
                    } else if (top.second.second > health) {
                        st.top().second.second--;
                        health = 0;
                        break;
                    } else {
                        st.pop();
                        health = 0;
                        break;
                    }
                }
                if (health > 0) {
                    st.push({pos, {dir, health}});
                }
            } else {
                st.push(num);
            }
        }

        while (!st.empty()) {
            int pos = st.top().first;
            int health = st.top().second.second;
            int index = ids[pos];
            temp[index] = health;
            st.pop();
        }

        vector<int> ans;

        for (auto it : temp) {
            if (it != 0) ans.push_back(it);
        }

        return ans;
    }
};
