#include <bits/stdc++.h>
using namespace std;

/** \brief      isValidSudoku  有效的数独
 *  \author     wzk
 *  \copyright  GNU Public License
 *  \version    1.0 
 *  \date       2020-1-7
 * 
 *  \param[in] nums 输入数组
 *  \return         false无效数独，true有效数独
 */ 
bool isValidSudoku(vector<vector<char>>& board) {
    unordered_set<char>  row;
    unordered_set<char>  col;
    unordered_set<char>  square;
    for (int i = 0; i < 9; ++i) {
        row.clear();
        col.clear();
        square.clear();
        for (int j = 0; j < 9; ++j) {
            if(board[i][j] != '.') {
                if(!row.insert(board[i][j]).second)
                    return false;
            }

            if(board[j][i] != '.') {
                if(!col.insert(board[j][i]).second)
                    return false;
            }

            int a = i / 3 * 3 + j / 3;
            int b = j % 3 + i % 3 * 3;
            if (board[a][b] != '.')
                if(!square.insert(board[a][b]).second)
                    return false; 
        }
    }
    return true;
}

int main(int argc, char *argv[])
{
    vector<vector<char>> nums = {
        {'8','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
        };

    bool ans = isValidSudoku(nums);
    std::cout << boolalpha << ans << std::endl;

    return 0;
}