/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

// Time Complexity: O(N^2)
// class Solution {
// private:
//     void makeGraph(TreeNode* root, TreeNode* prev, unordered_map<TreeNode*, vector<TreeNode*>>& adj, unordered_set<TreeNode*>& st){
//         if(root == NULL){
//             return;
//         }

//         if(root->left == NULL && root->right == NULL){
//             st.insert(root);
//         }

//         if(prev != NULL){
//             adj[root].push_back(prev);
//             adj[prev].push_back(root);
//         }

//         makeGraph(root->left, root, adj, st);
//         makeGraph(root->right, root, adj, st);
//     }
// public:
//     int countPairs(TreeNode* root, int distance) {
//         unordered_map<TreeNode*, vector<TreeNode*>> adj;
//         unordered_set<TreeNode*> st;

//         makeGraph(root, NULL, adj, st);

//         int cnt = 0;

//         for(auto leaf : st){
//             queue<TreeNode*> q;
//             unordered_set<TreeNode*> vis;
//             q.push(leaf);
//             vis.insert(leaf);

//             for(int level = 0; level <= distance; level++){
//                 int size = q.size();
//                 while(size--){
//                     TreeNode* curr = q.front();
//                     q.pop();

//                     if(curr!=leaf && st.count(curr)) cnt++;

//                     for(auto it : adj[curr]){
//                         if(!vis.count(it)){
//                             q.push(it);
//                             vis.insert(it);
//                         }
//                     }
//                 }
//             }
//         }

//         return cnt/2;
//     }
// };

// Time Complexity: O(N * D^2)
class Solution {
private:
    vector<int> dfs(TreeNode* root, int& dis, int& ans){
        if(root == NULL) return {};
        if(root->left == NULL && root->right == NULL) return {1};

        vector<int> leftR = dfs(root->left, dis, ans);
        vector<int> rightR = dfs(root->right, dis, ans);

        for(auto l : leftR){
            for(auto r : rightR){
                if(l+r <= dis) ans++;
            }
        }

        vector<int> parent;

        for(auto l : leftR){
            if(l+1 < dis) parent.push_back(l+1);
        }

        for(auto r : rightR){
            if(r+1 < dis) parent.push_back(r+1);
        }

        return parent;
    }
public:
    int countPairs(TreeNode* root, int distance) {
        int ans = 0;
        dfs(root, distance, ans);
        return ans;
    }
};