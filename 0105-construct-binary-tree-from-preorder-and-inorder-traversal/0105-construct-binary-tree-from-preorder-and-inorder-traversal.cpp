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
    TreeNode* buildTree(vector<int>& preorder, int preStart, int preEnd, vector<int>& inorder, int inStart, int inEnd, unordered_map<int, int>& mpp)
    {
        if(preEnd < preStart || inEnd < inStart) return NULL;

        TreeNode* root = new TreeNode(preorder[preStart]);
        int inIdx = mpp[preorder[preStart]];
        int numsLeft = inIdx - inStart;

        root->left = buildTree(preorder, preStart + 1, preStart + numsLeft, inorder, inStart, inIdx-1, mpp);
        root->right = buildTree(preorder, preStart + numsLeft + 1, preEnd, inorder, inIdx + 1, inEnd, mpp);

        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> mpp;
        int n = preorder.size();
        for(int i = 0; i < n; i++) mpp[inorder[i]] = i;
        
        TreeNode* res = buildTree(preorder, 0, n-1, inorder, 0, n-1, mpp);

        return res;
    }
};