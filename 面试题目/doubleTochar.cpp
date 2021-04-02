#include<stdio.h>
#include<stdlib.h>
#include<string.h>


void doubkeToString(double val, char *buf) {
    int i = 0;                                      /**<目标buf下标 */
    int j = 0;                                      /**<源下标str下标 */
    int point, sign;                                /**<point是小数点的位置，sign=1为负数且point<0 */
    char *str = ecvt(val, 16, &point, &sign);
    
    if (point <= 0) {                               /**<小于1的数*/
        /**<为负数，需要加上负号 */
        if (sign == 0){
            buf[i++] = '0';
            buf[i++] = '.';
        } else {
            buf[i++] = '-';
            buf[i++] = '0';
            buf[i++] = '.';
        }
        point = -point;
        while (point--)                             /**<0.0000xxx模式 */
            buf[i++] = '0';
        while (i < 15 && str[j]!='0')               /**<拷贝剩余数据,去除后面的0 */
            buf[i++] = str[j++];
    } else {                                        /**<大于1的数*/
        if (sign == 1) {
            buf[i++] = '-';
        }
        while (j < point)                           /**<开始copy */
            buf[i++] = str[j++];
        buf[i++]= '.';                              /**<添加小数点 */
        int pointI = i;
        int isAllZero = 1;
        while (i<15 && (isAllZero || str[j]!='0')) { /**<拷贝剩余位数,去除后面的0,前面的0要保留,-100.0001000 */
            if (str[j]!='0')
                isAllZero = 0;
            buf[i++] = str[j++];
        }
        if (isAllZero) {                            /**<100.0000000 */
            buf[pointI+1] = '\0';
        }
    }
}

int main(void)
{
    double val = -100.000010;
    char buf[16] = {0};


    // int point, sign;                                /**<point是小数点的位置，sign=1为负数且point<0 */
    // char *str = ecvt(val, 16, &point, &sign);
    // printf("str= %s\tpoint=%d\tsign=%d\n", str, point, sign);

    doubkeToString(val, buf);

    // gcvt(val, 10, buf);

    
    printf("str= %s\n", buf);
    
    return 0;
}


// main(){
// double a = 123.45;
// double b = -1234.56;
// char ptr[20];
// int decpt, sign;
// gcvt(a, 5, ptr);
// printf("a value=%s\n", ptr);
// // ptr = gcvt(b, 6, ptr);
// // printf("b value=%s\n", ptr);
// }