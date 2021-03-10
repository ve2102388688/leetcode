#include <bits/stdc++.h>
using namespace std;

/** \brief      searchMatrix 搜索二维矩阵 74
 *  \author     wzk
 *  \copyright  GNU Public License
 *  \version    1.0 
 *  \date       2020-3-9
 * 
 *  \param[in] nums   输入数组
 *  \return           峰值下标
 */
bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int m = matrix.size();
    int n = matrix[0].size();

    int low = 0, high = m*n - 1;                /**<将矩阵拉直 */
    while (low <= high) {
        int mid = low + (high - low) / 2;
        int i = mid / n, j = mid % n;           /**<还原原始二维矩阵横纵下标 */
        if (matrix[i][j] == target)
            return true;
        else if (matrix[i][j] > target)         
            high = mid - 1;
        else
            low = mid + 1;
    }
    return false;
}

int main(int argc, char *argv[])
{
    vector<vector<int>> nums1 = {{1,3,5,7},{10,11,16,20},{23,30,34,60}};
    bool output = searchMatrix(nums1, 3);
    cout << output << " ";

    cout << "\n";   
    return 0;
}