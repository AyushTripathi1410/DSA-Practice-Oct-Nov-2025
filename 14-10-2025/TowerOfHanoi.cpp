class Solution {
  public:
    int towerOfHanoi(int n, int from, int to, int aux) {
        if (n == 0) return 0;
        int moves1 = towerOfHanoi(n - 1, from, aux, to);
        // cout << "move disk " << n << " from rod " << from << " to rod " << to << endl;
        int moves2 = towerOfHanoi(n - 1, aux, to, from);
        return moves1 + 1 + moves2;
    }
};
