class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode *root) {
        vector<vector<int>> res;
        if(!root) return res;
        if(root -> left && root -> right){
            vector<vector<int>> left = levelOrderBottom(root -> left);
            vector<vector<int>> right = levelOrderBottom(root -> right);
            res = combine(left,right);
        }
        else if (root -> left || root -> right){
            vector<int> tmp;
            if(root -> left) tmp.push_back(root -> left -> val);
            if(root -> right) tmp.push_back(root -> right -> val);
            res.push_back(tmp);
        }
        vector<int> tmp;
        tmp.push_back(root -> val);
        res.push_back(tmp);
        return res;
    }
    vector<vector<int>> combine(vector<vector<int>> a, vector<vector<int>> b){
        int i = a.size();
        int j = b.size();
        vector<vector<int>> res;
        while(i > 0 || j > 0){
            vector<int> tmp;
            if(--j >= 0) tmp.insert(tmp.begin(),b[j].begin(),b[j].end());
            if(--i >= 0) tmp.insert(tmp.begin(),a[i].begin(),a[i].end());
            res.insert(res.begin(), tmp);
        }
        return res;
    }
};