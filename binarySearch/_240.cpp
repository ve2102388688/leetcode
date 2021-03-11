#include <bits/stdc++.h>
using namespace std;

/** \brief      searchMatrix 搜索二维矩阵II 240
 *  \author     wzk
 *  \copyright  GNU Public License
 *  \version    1.0 
 *  \date       2020-3-9
 *  \remark     超时 
 * 
 *  \param[in] matrix  输入矩阵
 *  \param[in] target  输入目标值
 *  \return           bool
 */
bool searchMatrix2(vector<vector<int>>& matrix, int target) {
    int m = matrix.size();
    int n = matrix[0].size();

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (matrix[i][j] == target)
                return true;
        }
    }
    return false;
}

/** \brief      searchMatrix 搜索二维矩阵II 240
 *  \author     wzk
 *  \copyright  GNU Public License
 *  \version    1.0 
 *  \date       2020-3-9
 *  \remark     从左下角到右上角搜索
 * 
 *  \param[in] matrix  输入矩阵
 *  \param[in] target  输入目标值
 *  \return           bool
 */
bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int m = matrix.size();
    int n = matrix[0].size();

    int i = m-1, j = 0;
    while (i>= 0&&i<m && j>=0&&j<n) {       /**<合法下标 */
        if (matrix[i][j] == target)
            return true;
        else if (matrix[i][j] > target)     /**<往下走 */
            --i;                    
        else
            ++j;                            /**<往右走 */
    }
    return false;
}

int main(int argc, char *argv[])
{
    vector<vector<int>> matrix = { { 1, 4, 7, 11, 15 }, { 2, 5, 8, 12, 19 }, { 3, 6, 9, 16, 22 }, { 10, 13, 14, 17, 24 }, { 18, 21, 23, 26, 30 } };
    bool output = searchMatrix(matrix, 31);
    cout << output << " ";

    cout << "\n";   
    return 0;
}