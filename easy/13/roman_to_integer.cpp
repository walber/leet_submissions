
#include <map>

typedef std::map<char,int> dict;

class Solution {
public:
    int romanToInt(string s) {
        int p, c, total;
        dict roman_d;

        roman_d['I'] = 1;
        roman_d['V'] = 5;
        roman_d['X'] = 10;
        roman_d['L'] = 50;
        roman_d['C'] = 100;
        roman_d['D'] = 500;
        roman_d['M'] = 1000;
        
        p = roman_d[s[0]];
        total = p;
        
        for (int i = 1; i < s.size(); i++) {
            c = roman_d[s[i]];
            total += (p < c) ? c - (2 * p) : c; 
            p = c;
        }
        
        return total;
    }
};
