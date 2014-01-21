/*
  Maximum Depth of Binary Tree 
  Given a binary tree, find its maximum depth.
  The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.
*/
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int maxDepth(TreeNode *root) {
        if(root == NULL)
            return 0;
        if((root->left ==NULL) && (root->right ==NULL))
            return 1;
        int leftdepth = maxDepth (root->left);
        int rightdepth = maxDepth (root->right);
        if(leftdepth > rightdepth)
            return leftdepth+1;
        else
            return rightdepth+1;
            
    }
};