//Attention: int overflow!
class Solution {
public:
    int uniquePaths(int m, int n) {
        if(m == 1 || n == 1) return 1;
        double res = 1;
        if(m < n){
            int tmp = m;
            m = n;
            n = tmp;
        }
        for(int i = m+n-2, j = n-1; j >= 1; i--, j--){
            res *= i;
            res /= j;
        }
        return (int)(res+0.5);
    }
};