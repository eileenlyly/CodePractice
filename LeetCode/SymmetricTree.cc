class Solution {
public:
    bool isSymmetric(TreeNode *root) {
        if(isMirror(root, root)) return true;
        return false;
    }
    bool isMirror(TreeNode *a, TreeNode *b){
        if(!a && !b) return true;
        if(!a || !b) return false;
        if(a -> val == b -> val)
            return isMirror(a -> right, b -> left) && isMirror(a -> left, b -> right);
        return false;
    }
};