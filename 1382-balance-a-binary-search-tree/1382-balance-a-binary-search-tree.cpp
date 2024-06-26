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
    void findInorder(TreeNode* root, vector<int>& nums) {
        if (root != nullptr) {
            findInorder(root->left, nums);
            nums.push_back(root->val);
            findInorder(root->right, nums);
        }
    }
    
    TreeNode* makeTree(vector<int>& nums, int low, int high) {
        if (low > high) { 
            return nullptr;
        }
        int mid = low + (high - low) / 2;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = makeTree(nums, low, mid - 1);
        root->right = makeTree(nums, mid + 1, high);
        return root;
    }
public:
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> inorder;
        findInorder(root, inorder);
        return makeTree(inorder, 0, inorder.size()-1);
    }
};