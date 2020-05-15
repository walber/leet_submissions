
#include <string>

class Solution {
public:
    int compress(vector<char>& chars) {
        int N, i, k, p;
        std::string::iterator s_k;
        string str_k;        
        char c;

        N = chars.size();
        c = chars[0];
        i = 0;
        k = 0;

        while (i < N) {
            while (i < N) {
                if (c == chars[i]) {
                    k++;
                    i++;
                }
                else {
                    c = chars[i];
                    break;
                }
            }
            
            if (k > 1) {
                str_k = std::to_string(k);
                s_k = str_k.begin();
                p = (i - k) + 1;
                
                while (s_k != str_k.end()) {
                    chars[p] = *s_k;
                    s_k++;
                    p++;
                }
                
                while (p < i) {
                    chars.erase(chars.begin() + p);
                    i--;
                    N--;
                }
            }
            
            k = 0;
        }
    
        return chars.size();
    }
};
