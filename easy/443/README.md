# 443. String Compression

#### Given an array of characters, compress it in-place. The length after compression must always be smaller than or equal to the original array. Every element of the array should be a character (not int) of length 1. After you are done modifying the input array in-place, return the new length of the array.

### Example 1:
```
Input:
["a","a","b","b","c","c","c"]

Output:
Return 6, and the first 6 characters of the input array should be: ["a","2","b","2","c","3"]

Explanation:
"aa" is replaced by "a2". "bb" is replaced by "b2". "ccc" is replaced by "c3".
```
### Example 2:
```
Input:
["a"]

Output:
Return 1, and the first 1 characters of the input array should be: ["a"]

Explanation:
Nothing is replaced.
```
### Example 3:
```
Input:
["a","b","b","b","b","b","b","b","b","b","b","b","b"]

Output:
Return 4, and the first 4 characters of the input array should be: ["a","b","1","2"].

Explanation:
Since the character "a" does not repeat, it is not compressed. "bbbbbbbbbbbb" is replaced by "b12".
Notice each digit has it's own entry in the array.
```
### Note:
```
All characters have an ASCII value in [35, 126].
1 <= len(chars) <= 1000.
```

## My Solutions:

### CPP:
```cpp
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
```
### Python:
```python
class Solution:
    def compress(self, chars: List[str]) -> int:
        N = len(chars)
        c = chars[0]
        i = 0
        k = 0

        while i < N:
            while i < N:
                if c == chars[i]:
                    k += 1
                    i += 1
                else:
                    c = chars[i]
                    break
            
            if k > 1:
                str_k = str(k)
                p = (i - k) + 1
                
                for s in str_k:
                    chars[p] = s
                    p += 1
                
                while p < i:
                    del chars[p]
                    i -= 1
                    N -= 1

            k = 0
```
