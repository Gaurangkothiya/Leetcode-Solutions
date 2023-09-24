class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int one = 0, zero = 0;
        for(char c:s){
            if(c == '0') zero++;
            else one++;
        }
        string ans = "";
        for(int i=1;i<one;i++) ans += '1';
        for(int i=1;i<=zero;i++) ans += '0';
        if(one >= 1) ans += '1';
        return ans;
    }
};