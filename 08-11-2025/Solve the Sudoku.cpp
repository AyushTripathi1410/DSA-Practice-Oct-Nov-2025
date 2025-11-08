class Solution {
  public:

    bool isSafe(int r, int c, int val, vector<vector<int>> &mat) {
        // Check row
        for (int j = 0; j < 9; j++)
            if (mat[r][j] == val) return false;
        for (int i = 0; i < 9; i++)
            if (mat[i][c] == val) return false;
        int sr = r - r % 3;
        int sc = c - c % 3;

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (mat[sr + i][sc + j] == val)
                    return false;
            }
        }

        return true;
    }

    bool solve(int r, int c, vector<vector<int>> &mat) {
        if (r == 9) return true;  

        if (c == 9) 
            return solve(r + 1, 0, mat);

        if (mat[r][c] != 0)
            return solve(r, c + 1, mat);

        for (int num = 1; num <= 9; num++) {
            if (isSafe(r, c, num, mat)) {
                mat[r][c] = num;
                if (solve(r, c + 1, mat)) return true;
                mat[r][c] = 0;  
            }
        }

        return false;
    }

    void solveSudoku(vector<vector<int>> &mat) {
        solve(0, 0, mat);
    }
};
