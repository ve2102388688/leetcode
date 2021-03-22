#include <bits/stdc++.h>
using namespace std;


/** \brief      backtrack 回溯函数
 *  \author     wzk
 *  \copyright  GNU Public License
 *  \version    1.0 
 *  \date       2020-3-16
 * 
 *  \param[in] board     输入字符表
 *  \param[in] i         输入横坐标
 *  \param[in] j         输入纵坐标
 *  \param[in] word      匹配字符串
 *  \param[in] k         匹配匹配字符位置
 *  \param[in] isrepeat  避免走回头路
 *  \param[in] track     轨迹
 *  \return              void
 */
bool answer = false;
void backtrack(vector<vector<char>> &board, int i, int j, string &word, int k, vector<char> &track, vector<vector<bool>> &isrepeat) {
    // 递归出口
    if(k==word.size()) {            /**<处理完最后一个结果，就等于给定字符串的长度了 */
        answer = true;
        return ;
    }

    // 选择列表上、下、左、右
    if (i>0 && isrepeat[i-1][j]==false){        /**<下一个位置是上 */
        if(board[i-1][j] == word[k]) {
            track.push_back(word[k]);
            isrepeat[i-1][j] = true;
            backtrack(board, i - 1, j, word, k + 1, track, isrepeat);
            track.pop_back();
            isrepeat[i-1][j] = false;
        }
    }
    if (i<board.size()-1 && isrepeat[i+1][j]==false  ){
        if(board[i+1][j] == word[k]) {
            track.push_back(word[k]);
            isrepeat[i+1][j] = true;
            backtrack(board, i+1, j, word, k+1, track, isrepeat);
            track.pop_back();
            isrepeat[i+1][j] = false;
        }
    }
    if (j>0 && isrepeat[i][j-1]==false ){
        if(board[i][j-1] == word[k]) {
            track.push_back(word[k]);
            isrepeat[i][j-1] = true;
            backtrack(board, i, j-1, word, k+1, track, isrepeat);
            track.pop_back();
            isrepeat[i][j-1] = false;
        }
    }
    if (j<board[0].size()-1 && isrepeat[i][j+1]==false){
        if(board[i][j+1] == word[k]) {
            track.push_back(word[k]);
            isrepeat[i][j+1] = true;
            backtrack(board, i, j+1, word, k+1, track, isrepeat);
            track.pop_back();
            isrepeat[i][j+1] = false;
        }
    }
    return;
}

/** \brief      exist 单词搜索 79
 *  \author     wzk
 *  \copyright  GNU Public License
 *  \version    1.0 
 *  \date       2020-3-16
 *  \remark     超出时间限制
 * 
 *  \param[in] board  输入字符表
 *  \param[in] word   匹配字符串
 *  \return           返回是否存在路径
 */
bool exist2(vector<vector<char>>& board, string& word) {
    /**<查找所有起点位置 */
    vector<vector<int>> cadidate;
    int m = board.size();
    int n = board[0].size();
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j)
            if (board[i][j]==word[0])
                cadidate.push_back({i,j});
    }

    vector<vector<bool>> isrepeat(m, vector<bool>(n, false));   /**<避免一个位置的字母重复使用 */
    for (const auto &e : cadidate) {
        vector<char> track;                         /**<track在递归回来依旧是空，所有需要提前将答案保存 */
        isrepeat[e[0]][e[1]] = true;                /**<由于第一个字母已经已知这里直接，压入，寻求下一个位置 */
        track.push_back(word[0]);
        backtrack(board, e[0], e[1], word, 1, track, isrepeat);     /**<这里一定是下一个匹配字母 */
        track.pop_back();
        isrepeat[e[0]][e[1]] = false;
        if (answer == true)
            return true;
    }
    return false;
}


bool dfs(vector<vector<char>>& board, int i, int j, string& word, int k) {
    if (k == word.size())
        return true;
    
    if (i<0 || i>=board.size() || j<0 || j>=board[0].size() || board[i][j]!=word[k])
        return false;

    char temp = board[i][j];
    board[i][j] = '0';              /**<标记 */
    /**<上下左右 */
    bool res = dfs(board, i-1, j, word, k + 1) ||
               dfs(board, i+1, j, word, k + 1) ||
               dfs(board, i, j-1, word, k + 1) ||
               dfs(board, i, j+1, word, k + 1);
    board[i][j] = temp;             /**<恢复标记 */
    return res;
}

bool exist(vector<vector<char>>& board, string& word) {
    vector<vector<int>> cadidate;
    int m = board.size();
    int n = board[0].size();
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j)
            if (board[i][j]==word[0])
                if(dfs(board, i, j, word, 0))
                    return true;
    }
      return false;
}

int main(int argc, char *argv[])
{
    vector<vector<char>> board = {{'A', 'B', 'C', 'E'},
                                   {'S', 'F', 'C', 'S'},
                                   {'A', 'D', 'E', 'E'}};                              
    string s = "ABCCEDA";
    bool output = exist(board, s);
    cout << output << "\n";

    return 0;
}