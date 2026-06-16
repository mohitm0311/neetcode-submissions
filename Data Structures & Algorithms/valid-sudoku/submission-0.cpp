class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            vector<bool> row_hash(10, false);
            vector<bool> col_hash(10, false);
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') {
                    int num = board[i][j] - '0';
                    if (row_hash[num]) {
                        return false;
                    }
                    row_hash[num] = true;
                }
                if (board[j][i] != '.') {
                    int num = board[j][i] - '0';
                    if (col_hash[num]) {
                        return false;
                    }
                    col_hash[num] = true;
                }
            }
        }
        for (int row = 0; row < 9; row += 3) {
            for (int col = 0; col < 9; col += 3) {
                vector<bool> box_hash(10, false);
                for (int i = row; i < row + 3; i++) {
                    for (int j = col; j < col + 3; j++) {
                        if (board[i][j] == '.') continue;
                        int num = board[i][j] - '0';
                        if (box_hash[num]) {
                            return false;
                        }
                        box_hash[num] = true;
                    }
                }
            }
        }
        return true;
    }
};
