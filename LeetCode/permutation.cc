class Solution {
public:
    
    vector<vector<int>> permute(vector<int> num) {
        vector<vector<int>> res;
        if(num.size() == 0) return res;
        if(num.size() == 1){
            vector<int> tmp(1,num[0]);
            res.push_back(tmp);
            return res;
        }
        for(int i = 0; i < num.size(); i++){
            vector<int> next(num);
            next.erase(next.begin()+i);
            vector<vector<int>> prev = permute(next);
            if(prev.size() != 0){
                for(int j = 0; j < prev.size(); j++){
                    prev[j].insert(prev[j].begin(),num[i]);
                    res.push_back(prev[j]);
                }
            }
        }
        return res;
    }
};