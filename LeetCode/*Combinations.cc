class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        if(k == 0 || k > n) return res;
        res = getCombine(n,k);
    }
    vector<vector<int>> getCombine(int n, int k){
        vector<vector<int>> res;
        if(k == 1){
            for(int i = 1; i <= n; i++){
                vector<int> tmp;
                tmp.push_back(i);
                res.push_back(tmp);
            }
            return res;
        }
        if(n == k){
            vector<int> tmp;
            for(int i = 1; i <= n; i++){
                tmp.push_back(i);
            }
            res.push_back(tmp);
            return res;
        }
        vector<vector<int>> v1 = getCombine(n-1,k-1);
        for(int i = 0; i < v1.size(); i++){
            v1[i].push_back(n);
            res.push_back(v1[i]);
        }
        vector<vector<int>> v2 = getCombine(n-1,k);
        for(int i = 0; i < v2.size(); i++){
            res.push_back(v2[i]);
        }
        return res;
    }
};