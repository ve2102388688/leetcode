#include <bits/stdc++.h>
using namespace std;

/** \brief      moveZeroes  移动零
 *  \author     wzk
 *  \copyright  GNU Public License
 *  \version    1.0 
 *  \date       2020-1-6
 * 
 *  \param[in] nums 输入数组
 *  \return         void
 */ 
void moveZeroes(vector<int>& nums) {
    if(nums.size() == 0){
        return;
    }

    int j = 0;
    for (int i = 0; i < nums.size(); ++i) {
        if(nums[i] != 0){               /**<只要不为0，交换，肯定的是nums[i]是0，除了自己和自己交换 */
            int temp = nums[i];
            nums[i] = nums[j];
            nums[j++] = temp;
        }
    }


    // /**<会改变次序 */
    // int size = nums.size();
    // int low = 0, high = size - 1;
    // while (low < high) {
    //     while (nums[low] != 0) ++low;           /**<找到为0的 */
    //     while (nums[high] == 0) --high;         /**<找到不为0的 */
    //     if(low < high){                         /**<这个条件不能少，否则会交换一次 */
    //         swap(&nums[low], &nums[high]);
    //         ++low, --high;
    //     }
    // }
}


int main(int argc, char *argv[])
{
    vector<int> nums = {1, 0};
    moveZeroes(nums);
    for(const auto& e : nums)
        std::cout << e << " ";
    std::cout << "\n";

    return 0;
}