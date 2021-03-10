#include <bits/stdc++.h>
using namespace std;

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

/** \brief      removeElement 移除元素 27
 *  \author     wzk
 *  \copyright  GNU Public License
 *  \version    1.0 
 *  \date       2020-1-29
 * 
 *  \param[in] nums 输入数组
 *  \param[in] val  被删除的数字
 *  \return         返回移除后的个数
 */
int removeElement(vector<int>& nums, int val) {
    int size = nums.size();
    if(size == 0)
        return 0;

    int low = 0;
    int high = size-1;
    while (low < high) {
        while (low < high && nums[low] != val) ++low;           /**<前面找相等的 */
        while (low < high && nums[high] == val) --high;         /**<后面找不相等的 */
        swap(&nums[low], &nums[high]);
    }
    if(nums[low] != val)                                        /**<数组中的值和val都不相等 */
        low += 1;

    return low;
}


int removeElement2(vector<int>& nums, int val) {
    int j = 0;
    int size = nums.size();
    for (int i = 0; i < size; ++i) {
        if(nums[i] != val){
            nums[j] = nums[i];
            ++j;
        }
    }
    return j;
}

int main(int argc, char *argv[])
{
    vector<int> nums = {4};

    int output = removeElement2(nums, 4);
    std::cout << output << '\n';

    return 0;
}