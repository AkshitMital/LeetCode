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
    pair<int, TreeNode*> solve(TreeNode* root) {
        if(root == NULL) return {0, NULL};

        auto left = solve(root->left);
        auto right = solve(root->right);

        if(left.first == right.first) return {left.first + 1, root};
        else if(left.first > right.first) return {left.first + 1, left.second};
        return {right.first + 1, right.second};
    }
public:
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        return solve(root).second;
    }
};