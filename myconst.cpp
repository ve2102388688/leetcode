// #include <stdio.h>
// #include <stdlib.h>

// // example of static array private member initialization
// class A
// {
// private:
//         static int array[20];

// public:
//         static void setArray();
// };

// int A::array[] = {0};

// void A::setArray()
// {
//         for (int i = 0; i < 20; i++)
//                 array[i] = i;
// }
// int main(int argc, char **argv)
// {
//         A foo;
//         foo.setArray();
//         return 0;
// }

#include <iostream>
//: C10:StaticArray.cpp
// Initializing static arrays in classes
class Values
{
        // static consts are initialized in-place:
        static const int scSize = 100;
        static const long scLong = 100;
        // Automatic counting works with static arrays.
        // Arrays, Non-integral and non-const statics
        // must be initialized externally:
        static const int scInts[];
        static const long scLongs[];
        static const float scTable[];
        static const char scLetters[];
        static int size;
        static const float scFloat;
        static float table[];
        static char letters[];
};

int Values::size = 100;
const float Values::scFloat = 1.1;

const int Values::scInts[] = {
    99, 47, 33, 11, 7};

const long Values::scLongs[] = {
    99, 47, 33, 11, 7};

const float Values::scTable[] = {
    1.1, 2.2, 3.3, 4.4};

const char Values::scLetters[] = {
    'a', 'b', 'c', 'd', 'e',
    'f', 'g', 'h', 'i', 'j'};

float Values::table[4] = {
    1.1, 2.2, 3.3, 4.4};

char Values::letters[10] = {
    'a', 'b', 'c', 'd', 'e',
    'f', 'g', 'h', 'i', 'j'};

int main()
{
        Values v;
        return 0;
} ///:~