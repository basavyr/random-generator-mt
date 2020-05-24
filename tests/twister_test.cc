#include "../include/twister.hh"

inline void line() { std::cout << '\n'; }

int main()
{
    std::cout << "twister: ok";
    auto x = std::make_unique<twister::Random>();
    line();
}