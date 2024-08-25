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
    int solve(TreeNode* root, int& maxSum){
        if(!root) return 0;

        int maxSumLH = solve(root->left, maxSum);
        int maxSumRH = solve(root->right, maxSum);
        maxSum = max(maxSum, root->val + maxSumLH + maxSumRH);

        return root->val + max(maxSumLH, maxSumRH);
    }
public:
    int maxPathSum(TreeNode* root) {
        int maxSum = INT_MIN;
        solve(root, maxSum);
        return maxSum;
    }
};