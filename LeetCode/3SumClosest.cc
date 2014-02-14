class Solution {
public:
    int threeSumClosest(vector<int> num, int target) {
        int n = num.size();
        sort(num.begin(),num.end());
        int min_diff = num[0] + num[1] + num[2] - target;
        for(int i = 0; i < n; i++){
            int val = num[i];
            num.erase(num.begin()+i);
            int diff = val + twoSumClosest(num, target-val) - target;
            num.insert(num.begin()+i,val);
            if(abs(diff) < abs(min_diff)) min_diff = diff;
            if (min_diff == 0) break;
        }
        return min_diff+target;
    }
    int twoSumClosest(vector<int> num, int target){
        int n = num.size()-1;
        int min_diff = num[0] + num[n] - target;
        int m = 0;
        while(m < n){
            int diff = num[m] + num[n] - target;
            if(abs(diff) > abs(min_diff)) break;
            min_diff = diff;
            if(min_diff < 0) m++;
            else if(min_diff > 0) n--;
            else if(min_diff == 0) break;
        }
        return min_diff+target;
    }
};