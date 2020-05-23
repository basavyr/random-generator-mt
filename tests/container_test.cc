#include "../include/container.hh"

#include <iostream>

inline void line() { std::cout << '\n'; }

int main()
{
    // std::cout << "container: ok";
    std::vector<int> no_size;
    std::vector<double> size;
    auto x = std::make_unique<container::Containers>(no_size);
    x->PrintContainer(no_size);
    line();
}