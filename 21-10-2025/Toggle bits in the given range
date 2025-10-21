class Solution {
  public:
    int toggleBits(int n, int l, int r) {
      
        int mask = ((1 << (r - l + 1)) - 1) << (l - 1);
        return n ^ mask;
    }
};
