// User function Template for C++
class Solution {
  public:
    int nthFibonacci(int n) {
        int MOD = 1000000007;
        if (n == 1 || n == 2) return 1;
        if(n==0) return 0;
        long long a = 1, b = 1, c;
        for (int i = 3; i <= n; i++) {
            c = (a + b) % MOD;
            a = b;
            b = c;
        }
        return b;
    }
};
