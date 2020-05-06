
class Solution {
public:
    string orderlyQueue(string S, int K) {
        int N, p, k;
        string s;
        N = S.size();

        if (K > 1) {
            sort(S.begin(), S.end());
            return S;
        }

        p = 0;
        for (int j = 0; j < N; j++) {
            if (S[p] > S[j]) {
                p = j;
            }
        }

        k = p;
        for (int j = p; j < N; j++) {
            if (S[p] == S[k]) {
                s = S.substr(k) + S.substr(0, k);
                if (lexicographical_compare(s.begin(), s.end(), S.begin(), S.end()) > 0) {
                    S = s;
                    p = 0;
                    k = 0;
                }
            }
            k += 1;
        }

        return S;
    }
};
