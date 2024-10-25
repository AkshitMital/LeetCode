// class TrieNode{
//     bool isEnd;
//     TrieNode* children[26];
//     friend class Trie;
// };

// class Trie{
// private:
//     TrieNode* root;
//     TrieNode* getNode(){
//         TrieNode* newNode = new TrieNode();
//         newNode->isEnd = false;
//         for(int i = 0; i < 26; i++) newNode->children[i] = NULL;
//         return newNode;
//     }
// public:
//     Trie(){ root = getNode(); }

//     bool insert(string s){
//         TrieNode* crawler = root;
//         for(char ch : s){
//             if(ch == '/') continue;
//             int idx = ch - 'a';
//             if(crawler->children[idx] == NULL) crawler->children[idx] = getNode();
//             if(crawler->isEnd == true) return false;
//             crawler = crawler->children[idx];
//         }
//         crawler->isEnd = true;
//         return true;
//     }
// };

class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin(), folder.end());
        vector<string> rootFolder;
        rootFolder.push_back(folder[0]);

        for(int i = 1; i < folder.size(); i++){
            string currFolder = folder[i];
            string lastFolder = rootFolder.back();
            lastFolder += '/';

            if(currFolder.find(lastFolder) != 0)
                rootFolder.push_back(currFolder);
        }

        return rootFolder;
    }
};