class TrieNode{
    bool isEnd;
    TrieNode* children[26];
    friend class Trie;
public:
    TrieNode(){
        isEnd = false;
        for(int i = 0; i < 26; i++) children[i] = NULL;
    }
};

class Trie{
private:
    TrieNode* root;
    bool searchHelper(TrieNode* node, string word, int index) {
        if (index == word.size()) {
            return node->isEnd;
        }
        
        char ch = word[index];
        
        if (ch == '.') {
            for (int i = 0; i < 26; i++) {
                if (node->children[i] != NULL) {
                    if (searchHelper(node->children[i], word, index + 1)) {
                        return true;
                    }
                }
            }
            return false;
        }

        int idx = ch - 'a';
        if (node->children[idx] == NULL) return false;
        return searchHelper(node->children[idx], word, index + 1);
    }
public:
    Trie(){
        root = new TrieNode();
    }

    void add(string word){
        TrieNode* crawler = root;
        for(int i = 0; i < word.size(); i++){
            int idx = word[i] - 'a';
            if(crawler->children[idx] == NULL) crawler->children[idx] = new TrieNode;
            crawler = crawler->children[idx];
        }
        crawler->isEnd = true;
    }

    bool search(string word){
        return searchHelper(root, word, 0);
    }
};

class WordDictionary {
    Trie trie;
public:
    WordDictionary() {
        
    }
    
    void addWord(string word) {
        trie.add(word);
    }
    
    bool search(string word) {
        return trie.search(word);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */