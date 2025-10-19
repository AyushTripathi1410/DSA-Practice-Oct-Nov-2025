class Solution {
public:
    int reverseExponentiation(int n) {
        int rev = 0;
        int temp = n;
        while (temp > 0) {
            int digit = temp % 10;
            rev = rev * 10 + digit;
            temp /= 10;
        }
        long long ans = 1;
        for (int i = 0; i < rev; i++) {
            ans *= n;
        }

        return ans;
    }
};
