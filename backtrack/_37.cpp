#include <bits/stdc++.h>
using namespace std;

bool isvaild(vector<vector<char>>& board, int r, int c, char ch) {
    for (int i = 0; i < 9; ++i) {
        if (board[r][i] == ch) return false;                    /**<一行中是否有重复 */
        if (board[i][c] == ch) return false;                    /**<一列中是否有重复 */
        if (board[(r/3)*3+i/3][(c/3)*3+i%3] == ch) return false;/**<一宫格是否有重复 */
    }
    return true;
}

/** \brief      backtrack 回溯函数
 *  \author     wzk
 *  \copyright  GNU Public License
 *  \version    1.0 
 *  \date       2020-2-19
 * 
 *  \param[in] board  输入棋盘
 *  \param[in] i      横坐标
 *  \param[in] j      纵坐标
 *  \return           bool
 */
bool backtrack(vector<vector<char>>& board, int i, int j) {
    /**<结束条件 */
    int m = 9, n = 9;
    if (j == n)                             /**<一行结束，换行 */
        return backtrack(board, i+1, 0);
    if (i == m)                             /**<最后一行结束 */
        return true;
    
    if (board[i][j] != '.')
        return backtrack(board, i, j + 1);
    
    for (char ch = '1'; ch <= '9'; ++ch) {
        if (!isvaild(board, i, j, ch))
            continue;
        board[i][j] = ch;                   /**<做选择 */
        if(backtrack(board, i, j + 1))
            return true;
        board[i][j] = '.'; /**<撤销选择 */
    }
    return false;                           /**<失败 */
}

/** \brief      solveSudoku 解数独 37
 *  \author     wzk
 *  \copyright  GNU Public License
 *  \version    1.0 
 *  \date       2020-2-19
 * 
 *  \param[in] board  输入棋盘
 *  \return           void
 */
void solveSudoku(vector<vector<char>>& board) {
    backtrack(board, 0, 0);
}

int main(int argc, char *argv[])
{
    vector<vector<char>> nums = {{'5','3','.','.','7','.','.','.','.'},
                                {'6','.','.','1','9','5','.','.','.'},
                                {'.','9','8','.','.','.','.','6','.'},
                                {'8','.','.','.','6','.','.','.','3'},
                                {'4','.','.','8','.','3','.','.','1'},
                                {'7','.','.','.','2','.','.','.','6'},
                                {'.','6','.','.','.','.','2','8','.'},
                                {'.','.','.','4','1','9','.','.','5'},
                                {'.','.','.','.','8','.','.','7','9'}};
    solveSudoku(nums);
    for (const auto&e : nums) {
        for (const auto&i : e)
            std::cout << i << ' ';
        std::cout << '\n';
    }
    cout << "\n";

    return 0;
}