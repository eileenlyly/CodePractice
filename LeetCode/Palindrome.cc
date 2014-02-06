class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0) return false;
        int digit = 1;
        while(x / digit >= 10) digit *= 10;
        while(digit > 1){
            int first = x / digit;
            int last = x % 10;
            if(first != last) return false;
            x = x % digit;
            x = x / 10;
            digit /= 100;
        }
        return true;
    }
};