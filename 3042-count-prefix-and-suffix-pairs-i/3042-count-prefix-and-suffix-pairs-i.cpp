class TrieNode {
    friend class Trie;
    TrieNode* children[26];
    bool isEnd;
};

class Trie {
private:
    TrieNode* root;
    TrieNode* getNode() {
        TrieNode* newNode = new TrieNode();
        newNode->isEnd = false;
        for(int i = 0; i < 26; i++) newNode->children[i] = NULL;
        return newNode;
    }
public:
    Trie() { root = getNode(); }

    void insert(string word) {
        TrieNode* crawler = root;
        for(int i = 0; i < word.size(); i++){
            int idx = word[i] - 'a';
            if(crawler->children[idx] == NULL) crawler->children[idx] = getNode();
            crawler = crawler->children[idx];
        }
        crawler->isEnd = true;
    }

    bool isPrefix(string prefix) {
        TrieNode* crawler = root;
        for(int i = 0; i < prefix.size(); i++){
            int idx = prefix[i] - 'a';
            if(crawler->children[idx] == NULL) return false;
            crawler = crawler->children[idx];
        }
        return true;
    }
};

class Solution {
public:
    int countPrefixSuffixPairs(vector<string>& words) {
        int n = words.size(), count = 0;

        for(int i = 0; i < n; i++){
            Trie prefixTrie;
            Trie suffixTrie;

            prefixTrie.insert(words[i]);
            string rev = words[i];
            reverse(rev.begin(), rev.end());

            suffixTrie.insert(rev);

            for(int j = 0; j < i; j++) {
                if(words[j].length() > words[i].length()) continue;

                string reversed = words[j];
                reverse(reversed.begin(), reversed.end());

                if(prefixTrie.isPrefix(words[j]) == true && suffixTrie.isPrefix(reversed) == true) count++;
            }
        }

        return count;
    }
};