
#define MAX_NUM 1000000007

class Solution {
public:
    long fact(int n) {
        long f = 1;
        
        if (n > 1) {
            for (int i = 2; i <= n; i++) {
                f = (f * i) % MAX_NUM;   
            }
        }
        
        return f % MAX_NUM;
    }

    int numPrimeArrangements(int n) {
        int not_prime = 1;
        vector<bool> num_list(n+1);

        for (int i = n; i > 1; i--) {
            for (int j = 2; j < n; j++) {
                if (i*j <= n) {
                    not_prime += num_list[i*j] ? 0 : 1;
                    num_list[i*j] = true;
                } else {
                    j = n;   
                }
            }
        }

        return (fact(not_prime) * fact(n - not_prime)) % MAX_NUM;
    }
};
