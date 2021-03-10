#include <bits/stdc++.h>
using namespace std;

/** \brief      generate 杨辉三角 118
 *  \author     wzk
 *  \copyright  GNU Public License
 *  \version    1.0 
 *  \date       2020-1-31
 * 
 *  \param[in] numRows  输入行数
 *  \return             返回杨辉三角
 */
vector<vector<int>> generate(int numRows) {
    if(numRows == 0)
        return {};

    vector<vector<int>> res;
    res.push_back({1});
    if(numRows == 1)                        /**<返回一个元素numRows==1 */
        return res;

    res.push_back({1,1});
    if(numRows == 2)                        /**<返回二个元素numRows==2 */
        return res;

    for (int i = 2; i < numRows; ++i) {
        vector<int> temp;
        temp.push_back(1);
        for(int j = 0; j < i-1; ++j) {     /**<每次计算i-1次即可 */ 
            temp.push_back(res[i - 1][j] + res[i - 1][j + 1]);
        }
        temp.push_back(1);
        res.push_back(temp);
    }
    return res;
}

int main(int argc, char *argv[])
{
    vector<vector<int>> output = generate(5);
    for(const auto& e : output){
        for(const auto& i : e)
            std::cout << i <<' ';
        std::cout << '\n';
    }

    return 0;
}