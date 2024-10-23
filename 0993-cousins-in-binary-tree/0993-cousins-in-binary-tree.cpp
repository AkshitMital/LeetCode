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
class Solution {
public:
    bool isCousins(TreeNode* root, int x, int y) {
        queue<TreeNode*> q;
        q.push(root);
        unordered_map<int, pair<int,int>> mpp; // node -> {parent, depth}
        mpp[root->val] = {-1, 0};

        while(!q.empty()){
            int sz = q.size();
            for(int i = 0; i < q.size(); i++){
                TreeNode* node = q.front();
                int currDist = mpp[node->val].second;
                q.pop();
                if(node->left){
                    q.push(node->left);
                    mpp[node->left->val] = {node->val, currDist+1};
                }
                if(node->right){
                    q.push(node->right);
                    mpp[node->right->val] = {node->val, currDist+1};
                }
            }
        }

        if(mpp[x].first != mpp[y].first && mpp[x].second == mpp[y].second) return true;

        return false;
    }
};