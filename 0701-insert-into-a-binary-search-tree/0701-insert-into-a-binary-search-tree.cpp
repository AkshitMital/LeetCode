// /**
//  * Definition for a binary tree node.
//  * struct TreeNode {
//  *     int val;
//  *     TreeNode *left;
//  *     TreeNode *right;
//  *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
//  * };
//  */
// class Solution {
// public:
//     TreeNode* insertIntoBST(TreeNode* root, int val) {
//         TreeNode* node = root;
//         TreeNode* ans = new TreeNode(val);
//         if(root==NULL) return ans;
//         while(node){
//             if(node->val<=val){
//                 if(node->right!=NULL) node = node->right;
//                 else{
//                     node->right = ans;
//                     break;
//                 }
//             }else{
//                 if(node->left!=NULL) node = node->left;
//                 else{
//                     node->left = ans;
//                     break;
//                 }
//             }
//         }
//         return root;
//     }
// };

class Solution {
public:
    
    TreeNode*help(TreeNode*root,int val){
        if(root==NULL)
            return new TreeNode(val);
        if(root->val > val)
            root->left=help(root->left,val);
        else
            root->right=help(root->right,val);
        return root;
    }
    TreeNode* insertIntoBST(TreeNode* root, int val) {
     return help(root,val);   
    }
};