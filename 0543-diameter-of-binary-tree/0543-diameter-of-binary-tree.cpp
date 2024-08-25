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
private:
    int maxHeight(TreeNode* root, int& ans){
        if(!root) return 0;

        int lh = maxHeight(root->left, ans);
        int rh = maxHeight(root->right, ans);

        ans = max(ans, lh + rh);

        return 1 + max(lh, rh);
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int ans = 0;
        maxHeight(root, ans);

        return ans;
    }
};