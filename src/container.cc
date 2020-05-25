
#include "../include/container.hh"
#include "../include/twister.hh"
static constexpr int standard_number = 69;

container::Containers::Containers(std::vector<int> &source) //basic case
{
    size = standard_number;
    norm = 1;
    //in the basic consturctor, only generate a random number between 0-100 to be introduced into the actual array
    auto random_giver = std::make_unique<twister::Random>(0, 100);
    for (auto id = 0; id < size; ++id)
    {
        auto element = static_cast<int>(random_giver->get_random() / norm);
        source.emplace_back(element);
    }
}

container::Containers::Containers(std::vector<int> &source, size_t v_size, int v_norm, int v_left, int v_right)
{
    size = v_size;
    norm = v_norm;
    left_limit = v_left;
    right_limit = v_right;
    auto random_giver = std::make_unique<twister::Random>(left_limit, right_limit);
    for (auto id = 0; id < size; ++id)
    {
        // auto element = static_cast<int>(random_giver->get_random() / norm);
        //adds the random element into the source array
        source.emplace_back(std::forward<int>(random_giver->get_random() / norm)); //optimized the passing of arguments in this function
        //changed the cast in forward to int due to refactor of random function
        //* TODO : don't create a dedicated variable to store the random number
    }
}

container::Containers::~Containers()
{
    (size != standard_number) && std::cout << "Container was generated successfully..." << '\n';
    (size == standard_number) && std::cout << "The default container was created due to missing info..." << '\n';
}