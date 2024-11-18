#include<map>
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
unordered_map<int,int> mpp;
private:
    TreeNode* solve(vector<int>& inorder, int inStart, int inEnd, vector<int>& postorder, int postStart, int postEnd)
    {
        if (inStart > inEnd || postStart > postEnd) return NULL;

        TreeNode* root = new TreeNode(postorder[postEnd]);
        int inRoot = mpp[root->val];
        int numsLeft = inRoot - inStart;

        root->left = solve(inorder, inStart, inRoot-1, postorder, postStart, postStart+numsLeft-1);
        root->right = solve(inorder, inRoot+1, inEnd, postorder, postStart+numsLeft, postEnd-1);

        return root;
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(inorder.size()!=postorder.size()) return NULL;
        int n = inorder.size();

        for(int i=0; i < n; i++) mpp[inorder[i]] = i;
        
        return solve(inorder, 0, n-1, postorder, 0, n-1);
    }
};