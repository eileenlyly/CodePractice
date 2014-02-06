class Solution {
public:
    double pow(double x, int n) {
        if(n < 0) return 1.0 / power(x, -n);
        return power(x, n);
    }
    double power(double x, int n){
        if(n == 0) return 1;
        if(n == 1) return x;
        double sqrt = power(x, n/2);
        if(n % 2 == 1) return sqrt * sqrt * x;
        return sqrt * sqrt;
    }
};