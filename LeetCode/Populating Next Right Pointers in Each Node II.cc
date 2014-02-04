class Solution {
public:
    void connect(TreeLinkNode *root) {
        if(!root) return;
        if(root -> left && root -> right) root -> left -> next = root -> right;
        if(RightMostChild(root)){
            TreeLinkNode *cur = new TreeLinkNode(-1);
            cur -> next = root;
            while(cur -> next -> next && !LeftMostChild(cur -> next -> next)) cur -> next = cur -> next -> next;
            if(cur -> next -> next) RightMostChild(root) -> next = LeftMostChild(cur -> next -> next);
        } 
        connect(root -> right);
        connect(root -> left);
    }
    TreeLinkNode * LeftMostChild(TreeLinkNode *root){
        if(root -> left) return root -> left;
        if(root -> right) return root -> right;
        return NULL;
    }
    TreeLinkNode * RightMostChild(TreeLinkNode *root){
        if(root -> right) return root -> right;
        if(root -> left) return root -> left;
        return NULL;
    }
};