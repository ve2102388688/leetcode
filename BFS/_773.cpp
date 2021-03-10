#include <bits/stdc++.h>
using namespace std;


/** \brief      slidingPuzzle 滑动谜题 773
 *  \author     wzk
 *  \copyright  GNU Public License
 *  \version    1.0 
 *  \date       2020-2-19
 * 
 *  \param[in] board 输入数组
 *  \return          返回达到目标需要最少的移动次数，不存在返回-1
 */
int slidingPuzzle(vector<vector<int>>& board) {
    int m = 2, n = 3;
    string start;                       /**<起始位置 */
    string target = "123450";           /**<目标位置 */
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            start.push_back(board[i][j] + '0');
        }
    }
    /**二维棋盘压缩成一维数组 ，记录二维中的上下左右位置信息 */
    vector<vector<int>> neighbor = {{1, 3},
                                    {0, 4, 2},
                                    {1, 5},
                                    {0, 4},
                                    {3, 1, 5},
                                    {4, 2}};

    queue<string> Q;
    Q.push(start);
    unordered_set<string> visited;              /**<防止重复访问 */
    visited.insert(start);

    int step = 0;
    while (!Q.empty()) {
        int size = Q.size();
        while (size > 0) {
            string node = Q.front(); Q.pop();
            /**出口 */ 
            if (node == target)
                return step;

            /**<查找零的位置 */
            int i = 0;
            while (node[i] != '0')  ++i;

            for (const auto& adj : neighbor[i]) {
                string new_board = node;
                swap(new_board[adj], new_board[i]);     /**<交换元素 */
                if (!visited.count(new_board)) {        /**<防止走回头路 */
                    Q.push(new_board);
                    visited.insert(new_board);

                }
            }
            --size;
        }
        ++step;
    }
    return -1;
}

int main(int argc, char *argv[])
{
    vector<vector<int>> nums = {{4,1,2},{5,0,3}};

    int output = slidingPuzzle(nums);
    std::cout << output << '\n';

    return 0;
}