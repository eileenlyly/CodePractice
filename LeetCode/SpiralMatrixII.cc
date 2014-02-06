class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res;
        if(!n) return res;
        res = generateCircle(n, n);
        return res;
    }
    vector<vector<int>> generateCircle(int n, int max){
        vector<vector<int>> res;
        if(n <= 0) return res;
        vector<vector<int>> core = generateCircle(n-2, max);
        int start = (max+n)*(max-n)+1;
        int end = start + 3*n - 3;
        vector<int> first, last;
        for(int i = 0; i < n; i++){
            first.push_back(start + i);
            last.push_back(end - i);
        }
        res.push_back(first);
        if(core.size() == 0){
            if(n == 2) res.push_back(last);
            return res;
        }
        int right = start + n;
        int left = start + 4*n -5;
        for(int i = 0; i < core.size(); i++){
            core[i].push_back(right++);
            core[i].insert(core[i].begin(), left--);
            res.push_back(core[i]);
        }
        res.push_back(last);
        return res;
    }
};