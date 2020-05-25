#ifndef TWISTER_HH
#define TWISTER_HH

// #include <cmath>
#include <iostream>
#include <memory>
#include <utility>
#include <random>
#include <algorithm>
namespace twister
{
    class Random
    {
    private:
        std::mt19937 mersenne_twister;
        uint32_t rd_copy;
        int left, right;

    public:
        Random(int, int);
        ~Random();

    public:
        int get_random();
    };

} // namespace twister

#endif // TWISTER_HH \
       //