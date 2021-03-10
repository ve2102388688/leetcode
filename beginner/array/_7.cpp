#include <bits/stdc++.h>
using namespace std;

/** \brief      add1  加1
 *  \author     wzk
 *  \copyright  GNU Public License
 *  \version    1.0 
 *  \date       2020-1-6
 * 
 *  \param[in] digits 输入数组
 *  \return           数字+1
 */ 
vector<int> plusOne(vector<int>& digits)
{
    // ******Method1
    int num9 = 0;                           // 9的个数
    int size = digits.size();
    while (num9 < size && digits[size - num9 - 1] == 9)     /**<统计9的个数，9是特例，要加上前面的判断*/
        ++num9;
    
    /**<三种情况，9的个数等于长度，等于0，小于长度 */
    if(num9 == 0) {                                         /**<没有9，全拷贝，最后一位+1*/
        digits[size-1] += 1;
        return digits;
    } else if (num9 == size) {                              /**<全是9，进位，后面全是0 */
        vector<int> res(size+1);            /**<vector<int>有默认初始化值 */
        res[0] = 1;
        return res;
    } else {                                                /**<个数9较少，前面拷贝，+1，后面全是0 */
        digits[digits.size()-num9-1] += 1;
        fill_n(digits.end()-num9, num9, 0);
        return digits;
    }

    // ******Method2，不改变数组值
    // vector<int> res;
    // int num9 = 0;                       // 9的个数
    // int size = digits.size();
    // while (num9 < size && digits[size - num9 - 1] == 9)
    //     ++num9;
    
    // /**<三种情况，9的个数等于长度，等于0，小于长度 */
    // if(num9 == 0) {                                         /**<没有9，全拷贝，最后一位+1*/
    //     copy(digits.begin(), digits.end(), back_inserter(res));
    //     res[size-1] += 1;
    // } else if(num9 == size){                                /**<全是9，进位，后面全是0 */
    //     res.push_back(1);
    //     fill_n(back_inserter(res), num9, 0);
    // } else {                                                /**<个数9较少，前面拷贝，+1，后面全是0 */
    //     copy(digits.begin(), digits.end()-num9, back_inserter(res));
    //     res[digits.size()-num9-1] += 1;
    //     fill_n(back_inserter(res), num9, 0);
    // }
    // return res;

    // // ******Method3
    // int size = digits.size();
    // for (int i = size-1; i >= 0; --i) {
    //     digits[i]++;
    //     digits[i] %= 10;
    //     if(digits[i] != 0)
    //         return digits;        
    // }

    // /**<处理全是9的情况 */
    // vector<int> res(size+1);            /**<vector<int>有默认初始化值 */
    // res[0] = 1;
    // return res;
}

int main(int argc, char *argv[])
{
    vector<int> nums = {9};
    vector<int> ans = plusOne(nums);

    for(const auto& e : ans)
        std::cout << e << " ";
    std::cout << "\n";

    return 0;
}