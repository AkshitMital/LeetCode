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
    int maxheight(TreeNode* root, bool& ans){
        if (root == NULL) {
            return 0;
        }

        int lh = maxheight(root->left, ans);
        int rh = maxheight(root->right, ans);
        
        if(abs(lh - rh) > 1){
            ans = false;
        }

        return max(lh, rh) + 1;
    }
public:
    bool isBalanced(TreeNode* root) {
        bool ans = true;
        maxheight(root, ans);
        return ans;
    }
};