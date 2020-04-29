
class Solution:
    def fact(self, n: int) -> int:
        f = 1

        for i in range(2, n + 1):
            f *= i
                
        return f

    def numPrimeArrangements(self, n: int) -> int:
        not_prime = 1
        num_list = [False] * (n+1)

        for i in range(n, 1, -1):
            for j in range(2, n):
                if i*j <= n:
                    not_prime += 0 if num_list[i*j] else 1
                    num_list[i*j] = True
                else:
                    break

        return (self.fact(not_prime) * self.fact(n - not_prime)) % (10**9 + 7)

