class TrieNode {
public:
    TrieNode* children[2];
    TrieNode(){
        children[0] = children[1] = NULL;
    }
};

class Trie {
public:
    TrieNode* root;
public:
    Trie(){
        root = new TrieNode();
    }

    void insert(int num){
        TrieNode* crawler = root;
        for(int i = 31; i >= 0; i--){
            int bit = (num >> i) & 1;
            if(crawler->children[bit] == NULL)
                crawler->children[bit] = new TrieNode();
            
            crawler = crawler->children[bit];
        }
    }

    int getMaxXOR(int num){
        TrieNode* crawler = root;
        int maxXOR = 0;
        for(int i = 31; i >= 0; i--){
            int bit = (num >> i) & 1;
            if(crawler->children[1-bit] != NULL){
                maxXOR = maxXOR | (1 << i);
                crawler = crawler->children[1-bit];
            }
            else crawler = crawler->children[bit];
        }

        return maxXOR;
    }
};

class Solution {
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        int n = queries.size();
        vector<int> ans(n, -1);
        sort(nums.begin(), nums.end());

        vector<vector<int>> sortedQ(n);
        for(int i = 0; i < n; i++) 
            sortedQ[i] = {queries[i][0], queries[i][1], i};
        
        auto lambda = [](vector<int>& a, vector<int>& b){
            return a[1] < b[1];
        };
        sort(sortedQ.begin(), sortedQ.end(), lambda);

        Trie trie;
        int idx = 0;

        for(int i = 0; i < n; i++){
            int xi = sortedQ[i][0];
            int mi = sortedQ[i][1];
            int ogIdx = sortedQ[i][2];

            while (idx < nums.size() && nums[idx] <= mi) {
                trie.insert(nums[idx]);
                idx++;
            }

            if (idx > 0) {
                ans[ogIdx] = trie.getMaxXOR(xi);
            }
        }

        return ans;
    }
};