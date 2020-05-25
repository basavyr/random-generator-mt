#ifndef CONTAINER_HH
#define CONTAINER_HH

#include <vector>
#include <utility>
#include <functional>
#include <memory>
#include <fstream>
#include <iostream>
#include <algorithm> //if_any

namespace container
{
    class Containers
    {
    private:
        size_t size;                 //declare the size of the container to store the random data
        int norm;                    //?optional: declare a constant value fort normalizing the data set to it
        int left_limit, right_limit; //chose the interval in which the random data should be generated

    public:
        //* the default constructor without input parameters: it defaults to an int-type vector
        Containers(std::vector<int> &source);
        //* the constructor with input parameters: it takes the size of the array, norm and random generator limits as parameters.
        //*type of the array is int in this case
        //reason for only working with integers is that the "uniform_int_distribution" is a better choice for working with consistent randomness
        Containers(std::vector<int> &source, size_t size, int norm, int left, int right);
        ~Containers();

    public:
        template <typename T>
        static void PrintContainer(std::vector<T> &cont)
        {
            for (auto &&n : cont)
            {
                std::cout << n << " ";
            }
            std::cout << '\n';
        }
        template <typename T>
        static void PrintContainerToFile(std::ofstream &out, std::vector<T> &cont)
        {
            for (auto &&n : cont)
            {
                out << n << " ";
            }
            out << '\n';
        }
    };
} // namespace container

#endif // CONTAINER_HH
