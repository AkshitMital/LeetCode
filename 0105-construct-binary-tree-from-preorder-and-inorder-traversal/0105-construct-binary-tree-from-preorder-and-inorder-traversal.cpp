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
        if(preStart > preEnd || inStart > inEnd) return NULL;

        TreeNode* root = new TreeNode(preorder[preStart]);
        int inRoot = mpp[preorder[preStart]];
        int preLeft = inRoot - inStart;

        root->left = buildTree(preorder, preStart + 1, preStart + preLeft, inorder, inStart, inRoot-1, mpp);
        root->right = buildTree(preorder, preStart + preLeft + 1, preEnd, inorder, inRoot+1, inEnd, mpp);

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