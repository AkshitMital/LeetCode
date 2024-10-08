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
    int helper(TreeNode* root, int maxi){
        if(root == NULL) return 0;

        int isGoodNode = 0;
        if(root->val >= maxi) isGoodNode = 1;

        maxi = max(maxi, root->val);
        int left = helper(root->left, maxi);
        int right = helper(root->right, maxi);

        return isGoodNode + left + right;
    }
public:
    int goodNodes(TreeNode* root) {
        return helper(root, INT_MIN);
    }
};