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
    TreeNode* replaceValueInTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int levelSum = root->val;

        while(!q.empty()){
            int sz = q.size();
            int nxtLevelSum = 0;
            for(int i = 0; i < sz; i++){
                TreeNode* node = q.front();
                q.pop();
                int siblingSum = 0;

                node->val = levelSum - node->val;

                if(node->left) siblingSum += node->left->val;
                if(node->right) siblingSum += node->right->val;

                nxtLevelSum += siblingSum;

                if(node->left){
                    node->left->val = siblingSum;
                    q.push(node->left);
                }
                if(node->right){
                    node->right->val = siblingSum;
                    q.push(node->right);
                }
            }

            levelSum = nxtLevelSum;
        }

        return root;
    }
};