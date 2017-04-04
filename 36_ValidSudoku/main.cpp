#include <vector>
#include <iostream>

using namespace std;

void output(const vector<vector<char>>& board) {
    for (size_t i = 0; i < board.size(); ++i) {
        for (size_t j = 0; j < board[i].size(); ++j) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

class Solution {
public:
    bool check_vec_valid(const vector<char>& vec) {
        vector<int> char_cnt(256, 0);
        for(size_t i = 0; i < vec.size(); ++i) {
            if (vec[i] != '.') {
                char_cnt[vec[i]]++;
            }
        }

        for(size_t i = 0; i < char_cnt.size(); ++i) {
            if (char_cnt[i] > 1) {
                return false;
            }
        }
        return true;
    }

    bool isValidSudoku(vector<vector<char>>& board) {
        if (board.size() != 9) {
            return false;
        }
        for (size_t i = 0; i < board.size(); ++i) {
            if (board[i].size() != 9) {
                return false;
            }
            for (size_t j = 0; j < board[i].size(); ++j) {
                if (board[i][j] != '.' && (board[i][j] > '9' || board[i][j] < '0')) {
                    return false;
                }
            }
        }

        //line check
        for (size_t i = 0; i < board.size(); ++i) {
            if (!check_vec_valid(board[i])) {
                return false;
            }
        }

        //col check
        for (size_t i = 0; i < 9; ++i) {
            vector<char> col;
            for (size_t j = 0; j < board.size(); ++j) {
                col.push_back(board[j][i]);
            }
            if (!check_vec_valid(col)) {
                return false;
            }
        }
        
        //block check
        for (size_t i = 0; i < 3; ++i) {
            for (size_t j = 0; j < 3; ++j) {
                vector<char> block;
                for (size_t block_i = 0; block_i < 3; ++block_i) {
                    for (size_t block_j = 0; block_j < 3; ++block_j) {
                        block.push_back(board[i*3 + block_i][j*3 + block_j]);
                    }
                }
                if (!check_vec_valid(block)) {
                    return false;
                }
            }
        }

        //else return true
        return true;
        
    }
};

int main () {
    vector<vector<char>> board {
        {'.', '.', '4', '.', '.', '.', '6', '3', '.'},
        {'.', '.', '.', '.', '.', '.', '.', '.', '.'},
        {'5', '.', '.', '.', '.', '.', '.', '9', '.'},
        {'.', '.', '.', '5', '6', '.', '.', '.', '.'},
        {'4', '.', '3', '.', '.', '.', '.', '.', '1'},
        {'.', '.', '.', '7', '.', '.', '.', '.', '.'},
        {'.', '.', '.', '5', '.', '.', '.', '.', '.'},
        {'.', '.', '.', '.', '.', '.', '.', '.', '.'},
        {'.', '.', '.', '.', '.', '.', '.', '.', '.'},
    };
//    vector<vector<char>> board {
//        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
//        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
//        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
//        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
//        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
//        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
//        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
//        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
//        {'.', '.', '.', '.', '8', '.', '.', '7', '9'},
//    };

    output(board);

    Solution s;
    cout << s.isValidSudoku(board) << endl;

    return 0;
}
