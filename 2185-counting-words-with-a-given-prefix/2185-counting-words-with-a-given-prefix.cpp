class TrieNode {
    friend class Trie;
    TrieNode* children[26];
    bool isEnd;
    int count;
};

class Trie {
    TrieNode* root;
    TrieNode* getNode() {
        TrieNode* newNode = new TrieNode();
        for(int i = 0; i < 26; i++) newNode->children[i] = NULL;
        newNode->isEnd = false;
        newNode->count = 0;
        return newNode;
    }
public:
    Trie() { root = getNode(); }

    void insert(string& word) {
        TrieNode* crawler = root;
        for(int i = 0; i < word.size(); i++){
            int idx = word[i] - 'a';
            if(crawler->children[idx] == NULL) crawler->children[idx] = getNode();
            crawler = crawler->children[idx];
            crawler->count++;
        }
        crawler->isEnd = true;
    }

    int searchPrefix(string& prefix) {
        TrieNode* crawler = root;
        for(int i = 0; i < prefix.size(); i++){
            int idx = prefix[i] - 'a';
            if(crawler->children[idx] == NULL) return 0;
            crawler = crawler->children[idx];
        }
        return crawler->count;
    }
};

class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        Trie trie;

        for(auto word : words) trie.insert(word);

        return trie.searchPrefix(pref);
    }
};