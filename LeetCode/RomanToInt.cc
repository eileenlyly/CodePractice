//I（1）、V（5）、X（10）、L（50）、C（100）、D（500）和M（1000)
class Solution {
public:
    int map (char c){
        switch(c){
            case 'I': return 1;
            case 'V': return 5;
            case 'X': return 10;
            case 'L': return 50;
            case 'C': return 100;
            case 'D': return 500;
            case 'M': return 1000;
        }
    }
    int romanToInt(string s) {
        if(s.length() < 1) return NULL;
        int num = 0;
        for(int i = 0; i < s.length()-1; i++){
            if(map(s[i]) < map(s[i+1])) num -= map(s[i]);
            else num += map(s[i]);
        }
        num += map(s[s.length()-1]);
        return num;
    }
};