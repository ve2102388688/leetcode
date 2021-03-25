#include <bits/stdc++.h>
using namespace std;


/** \brief      canPlaceFlowers 种花问题 605
 *  \author     wzk
 *  \copyright  GNU Public License
 *  \version    1.0 
 *  \date       2020-3-23
 * 
 *  \param[in] flowerbed  花坛
 *  \param[in] N          种花数目
 *  \return               能否种花
 */
bool canPlaceFlowers(vector<int>& flowerbed, int n) {
    int size = flowerbed.size();
    for (int i = 0; i < size&&n>0; ) {
        if(flowerbed[i])
            i += 2;                 /**<种花步数加2 */
        else if(i<size-1&& flowerbed[i+1]==0) {
            --n;                    /**<可以种花 */
            i += 2;
        } else
            i += 3;                 /**<条三格 */
    }
    return n <= 0;
}

int main(int argc, char *argv[])
{
    vector<int> nums = {1,0,0,0,1,0,0};

    bool output = canPlaceFlowers(nums, 2);
    std::cout << output << '\n';

    return 0;
}