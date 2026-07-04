class Solution {
public:
    int countGoodNumbers(long long n) {
        long long even = (n + 1) / 2;
        long long odd = n / 2;

        long long ans = (power(5, even) * power(4, odd)) % MOD;

        return ans;
        
    }

    const long long MOD = 1e9 + 7;

    long long power(long long a, long long b) {
        long long ans = 1;

        while (b > 0) {
            if (b & 1)
                ans = (ans * a) % MOD;

            a = (a * a) % MOD;
            b >>= 1;
        }

        return ans;
    }
};