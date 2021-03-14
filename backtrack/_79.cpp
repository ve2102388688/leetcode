#include <bits/stdc++.h>
using namespace std;


/** \brief      backtrack 回溯函数
 *  \author     wzk
 *  \copyright  GNU Public License
 *  \version    1.0 
 *  \date       2020-2-4
 * 
 *  \param[in] left   左括号数量
 *  \param[in] right  右括号数量
 *  \param[in] track  轨迹
 *  \return           void
 */
void backtrack(vector<vector<char>>& board, int i, int j, string& word, int k, vector<char>& track, vector<vector<bool>>& isrepeat) {
    // 递归出口
    if(k==word.size()-1)
        return;

    // 选择列表上、下、左、右
    if (isrepeat[i][j]==false && i>0){
        if(board[i][j] == word[k]) {
            track.push_back(word[k]);
            isrepeat[i][j] = true;
            backtrack(board, i - 1, j, word, k + 1, track, isrepeat);
            track.pop_back();
            isrepeat[i][j] = false;
        }
    }
    if (isrepeat[i][j]==false && i<board.size()-1){
        if(board[i][j] == word[k]) {
            track.push_back(word[k]);
            isrepeat[i][j] = true;
            backtrack(board, i+1, j, word, k+1, track, isrepeat);
            track.pop_back();
            isrepeat[i][j] = false;
        }
    }
    if (isrepeat[i][j]==false && j>0){
        if(board[i][j] == word[k]) {
            track.push_back(word[k]);
            isrepeat[i][j] = true;
            backtrack(board, i, j-1, word, k+1, track, isrepeat);
            track.pop_back();
            isrepeat[i][j] = false;
        }
    }
    if (isrepeat[i][j]==false && j<board[0].size()-1){
        if(board[i][j] == word[k]) {
            track.push_back(word[k]);
            isrepeat[i][j] = true;
            backtrack(board, i, j+1, word, k+1, track, isrepeat);
            track.pop_back();
            isrepeat[i][j] = false;
        }
    }
    return;
}

/** \brief      generateParenthesis 括号生成 22
 *  \author     wzk
 *  \copyright  GNU Public License
 *  \version    1.0 
 *  \date       2020-2-4
 *  \remark     寻找一条路符合word
 * 
 *  \param[in] n  输入数组
 *  \return       返回合法括号组
 */
bool exist(vector<vector<char>>& board, string& word) {
    /**<查找所有起点位置 */
    vector<vector<int>> cadidate;
    int m = board.size();
    int n = board[0].size();
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j)
            if (board[i][j]==word[0])
                cadidate.push_back({i,j});
    }

    vector<vector<bool>> isrepeat(m, vector<bool>(n, false));
    for (const auto &e : cadidate)
    {
        vector<char> track;
        backtrack(board, e[0], e[1], word, 0, track, isrepeat);
        if (track.size() == word.size())
            return true;
    }
    return false;
}

int main(int argc, char *argv[])
{
    vector<vector<char>> board = {{'A', 'B', 'C', 'E'},
                                   {'S', 'F', 'C', 'S'},
                                   {'A', 'D', 'E', 'E'}};                              
    string s = "ABCCED";
    bool output = exist(board, s);
    cout << output << "\n";

    return 0;
}