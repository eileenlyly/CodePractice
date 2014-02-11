class Solution {
public:
    string countAndSay(int n) {
        string s = "1";
        while(--n){
            s = getNext(s);
        }
        return s;
    }
    string getNext(string s){
        string res = "";
        int count = 0;
        char cur = s[0];
        for(int i = 0; i <= s.length(); i++){
            if(s[i] == cur) count++;
            if(s[i] != cur){
                res += to_string(count);
                res += cur;
                cur = s[i];
                count = 1;
            }
        }
        return res;
    }
};