#include <bits/stdc++.h>
using namespace std;

/** \brief      getRow 杨辉三角 119
 *  \author     wzk
 *  \copyright  GNU Public License
 *  \version    1.0 
 *  \date       2020-1-31
 * 
 *  \param[in] numRows  输入行数
 *  \return             返回杨辉三角
 */
vector<int> getRow(int rowIndex) {
    vector<int> res(rowIndex+1);
    res[0] = 1;
    long long int temp = 1;                     /**<防止int越界*/
    for (int i = 1; i <= rowIndex; ++i) {
        temp = temp * (rowIndex - i + 1) / i;   /**<组合公式 */
        res[i] = temp;
    }

    return res;
}

int main(int argc, char *argv[])
{
    vector<int> output = getRow(5);
    for(const auto& e : output){
        std::cout << e <<' ';
    }
    std::cout << '\n';

    return 0;
}