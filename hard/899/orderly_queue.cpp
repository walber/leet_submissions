
class Solution {
public:
    string orderlyQueue(string S, int K) {
        int N, k;
        string s;
        char c;
        N = S.size();

        if (K > 1) {
            sort(S.begin(), S.end());
            return S;
        }

        k = 0;
        for (int j = 1; j < N; j++) {
            if (S[k] > S[j]) {
                k = j;
            }
        }

        s = S;
        c = S[k];
        for (int j = k; j < N; j++, k++) {
            if (c == S[k]) {
                S = S.substr(k) + S.substr(0, k);
                k = 0;
                if (lexicographical_compare(S.begin(), S.end(), s.begin(), s.end()) > 0) {
                    s = S;
                }
            }
        }

        return s;
    }
};
