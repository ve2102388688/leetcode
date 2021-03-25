#include <bits/stdc++.h>
using namespace std;


/** \brief      lemonadeChange 柠檬水找零 860
 *  \author     wzk
 *  \copyright  GNU Public License
 *  \version    1.0 
 *  \date       2020-3-22
 * 
 *  \param[in] bills  账单顺序
 *  \return           能否正确找零
 */
bool lemonadeChange(vector<int>& bills) {
    int n = bills.size();
    if (n == 0)
        return true;
    if (bills[0] == 10 || bills[0] == 20)       /**<10、20开头的直接false*/
        return false;
    
    int num5 = 0, num10 = 0;                    /**<其实三种金额的数量 */
    for (int i = 0; i < n; ++i) {
        if (bills[i] == 5) {                    /**<遇到五元直接收 */
            ++num5;
        } else if(bills[i] == 10) {             /**<遇到十元直接收，找五元 */
            if (num5 == 0)
                return false;
            else
                --num5, ++num10;
        }  else if(bills[i] == 20) {            /**<遇到二十元直接收，找十五元 */
            if (num10 != 0 && num5 != 0)
                --num10, --num5;
            else if (num10 == 0 && num5 != 0){
                num5 -= 3;
                if (num5<0)
                    return false;
            } else
                return false;
        }
    }
    return true;
}

int main(int argc, char *argv[])
{
    vector<int> nums = {5,5,10,10,20};

    bool output = lemonadeChange(nums);
    std::cout << output << '\n';

    return 0;
}