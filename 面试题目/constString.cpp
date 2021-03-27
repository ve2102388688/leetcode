#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[])
{
    char str1[] = "hello world";
    char str2[] = "hello world";

    if (str1 == str2)
        cout << "str1 and str2 are same.\n";
    else
        cout << "str1 and str2 are not same.\n";        // ok

    char *str3 = "hello world";
    char *str4 = "hello world";
    if (str3 == str4)
        cout << "str3 and str4 are same.\n";            // ok
    else
        cout << "str3 and str4 are not same.\n";

    return 0;
}