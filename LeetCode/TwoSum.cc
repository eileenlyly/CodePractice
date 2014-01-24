class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        vector<int> res;
        vector<int> diff;
        for(int i = 0; i < numbers.size(); i++){
            vector<int>::iterator find = std::find(diff.begin(),diff.end(),numbers[i]);
            if(find != diff.end()){
                res.push_back(std::distance(diff.begin(),find)+1);
                res.push_back(i+1);
                break;
            }
            int y = target - numbers[i];
            diff.push_back(y);
        }
        return res;
    }
};