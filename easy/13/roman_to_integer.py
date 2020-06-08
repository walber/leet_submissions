
class Solution:
    def romanToInt(self, s: str) -> int:
        
        roman_d = { 'I': 1, 'V': 5, 'X': 10, 'L': 50, 'C': 100, 'D': 500, 'M': 1000 }
        p = roman_d[s[0]]
        total = p

        for i in range(1,len(s)):
            c = roman_d[s[i]]
            total += c - (2 * p) if p < c else c
            p = c
        
        return total
