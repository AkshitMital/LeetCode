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
    TreeNode* helper(TreeNode* root){
        if(root->left==NULL) return root->right;
        else if(root->right==NULL) return root->left;

        TreeNode* leftChild = root->left;
        TreeNode* lastLeft = findLastLeft(root->right);
        lastLeft->left = leftChild;
        return root->right;
    }
    TreeNode* findLastLeft(TreeNode* root){
        if(root->left==NULL){
            return root;
        }
        return findLastLeft(root->left);
    }
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==NULL){
            return NULL;
        }
        if(root->val==key){
            return helper(root);
        }
        TreeNode* node = root;
        while(node){
            if(node->val<key){
                if(node->right!=NULL && node->right->val == key){
                    node->right = helper(node->right);
                    break;
                }else{
                    node = node->right;
                }
            }
            else{
                if(node->left!=NULL && node->left->val == key){
                    node->left = helper(node->left);
                    break;
                }else{
                    node = node->left;
                }
            }
        }
        return root;
    }
};