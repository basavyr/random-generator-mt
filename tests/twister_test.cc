#include "../include/twister.hh"

inline void line() { std::cout << '\n'; }

int main()
{
    auto x = std::make_unique<twister::Random>(1, 100);
}