class Solution {
private:
    void solve(string& curr, vector<bool>& used, unordered_set<string>& st, string& tiles, int& n) {
        st.insert(curr);

        for(int i = 0; i < n; i++) {
            if(used[i]) continue;

            used[i] = true;
            curr.push_back(tiles[i]);

            solve(curr, used, st, tiles, n);

            used[i] = false;
            curr.pop_back();
        }
    }   
public:
    int numTilePossibilities(string tiles) {
        int n = tiles.size();

        unordered_set<string> st;
        string curr = "";
        vector<bool> used(n, false);

        solve(curr, used, st, tiles, n);

        return st.size() - 1; //exclude empty string
    }
};