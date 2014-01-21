/*
Reverse digits of an integer.

Example1: x = 123, return 321
Example2: x = -123, return -321
*/
class Solution {
public:
    int reverse(int x) {
        int y = 0;
        while(x){
            y = y*10 + x%10;
            x = x/10;
        }
        return y;
    }
};