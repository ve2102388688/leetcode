#include <bits/stdc++.h>
using namespace std;

 
void swap(int *a, int *b)
{
    int temp  = *a;
    *a = *b;
    *b = temp;
}

/** \brief      rotate  顺时针旋转90
 *  \author     wzk
 *  \copyright  GNU Public License
 *  \version    1.0 
 *  \date       2020-1-7
 * 
 *  \param[in] matrix 输入矩阵
 *  \return         void
 */ 
void rotate(vector<vector<int>>& matrix) {
    int size = matrix.size();
    // 副对角线翻折
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size-i; ++j) {
            swap(&matrix[i][j], &matrix[size - 1 - j][size - 1 - i]);
        }
    }
    // 水平翻折
    for (int i = 0; i < size/2; ++i) {
        for (int j = 0; j < size; ++j) {
            swap(&matrix[i][j], &matrix[size - 1 - i][j]);
        }
    }
}

int main(int argc, char *argv[])
{
    vector<vector<int>> nums = {
        {1,2,3},
        {4,5,6},
        {7,8,9}
        };

    rotate(nums);
    
    for (size_t i = 0; i < nums.size(); ++i) {
        for (size_t j = 0; j < nums.size(); ++j) {
            std::cout << nums[i][j] << " ";
        }
        std::cout << "\n";
    }

    return 0;
}