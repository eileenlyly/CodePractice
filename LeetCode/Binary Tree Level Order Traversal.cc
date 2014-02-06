class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode *root) {
        vector<vector<int>> res;
        if(!root) return res;
        vector<vector<int>> left = levelOrder(root -> left);
        vector<vector<int>> right = levelOrder(root -> right);
        res = combine(left, right);
        vector<int> tmp;
        tmp.push_back(root -> val);
        res.insert(res.begin(), tmp);
        return res;
    }
    vector<vector<int>> combine (vector<vector<int>> a, vector<vector<int>> b){
        int i = a.size();
        if(!i) return b;
        int j = b.size();
        if(!j) return a;
        vector<vector<int>> res;
        for(int m = 0, n = 0; m < i || n < j; m++, n++){
            vector<int> tmp;
            if(n < j) tmp.insert(tmp.begin(), b[n].begin(), b[n].end());
            if(m < i) tmp.insert(tmp.begin(), a[m].begin(), a[m].end());
            res.push_back(tmp);
        }
        return res;
    }
};