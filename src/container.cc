
#include "../include/container.hh"

static constexpr int standard_number = 69;

container::Containers::Containers(std::vector<int> &source) //basic case
{
    size = standard_number;
    norm = 1;
    for (auto id = 0; id < size; ++id)
    {
        auto element = static_cast<int>(standard_number / norm);
        source.emplace_back(element);
    }
}

container::Containers::Containers(std::vector<double> &source, size_t v_size, double v_norm, double v_left, double v_right)
{
    size = v_size;
    norm = v_norm;
    left_limit = v_left;
    right_limit = v_right;
    for (auto id = 0; id < size; ++id)
    {
        //!needs the random element
        auto element = static_cast<double>(standard_number / norm);
        source.emplace_back(std::forward<double>(element)); //?optimize the passing of arguments in this function
        //TODO : don't create a dedicated variable to store the random number
    }
}

container::Containers::~Containers()
{
    (size != standard_number) && std::cout << "Container was generated successfully..." << '\n';
    (size == standard_number) && std::cout << "The default container was created due to missing info..." << '\n';
}