class Solution {
public:
    int maxArea(vector<int> &height) {
        int n = height.size()-1;
        if(n < 1) return 0;
        int m = 0, max_water = 0;
        while(m < n){
            max_water = max(max_water, min(height[m], height[n])*(n-m));
            if(height[m] < height[n]) m++;
            else n--;
        }
        return max_water;
    }
};