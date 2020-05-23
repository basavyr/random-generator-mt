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
        size_t size;                    //declare the size of the container to store the random data
        double norm;                    //?optional: declare a constant value fort normalizing the data set to it
        double avg;                     //store the computed average from the array
        double left_limit, right_limit; //chose the interval in which the random data should be generated

    public:
        //* the default constructor without input parameters: it defaults to an int-type vector
        Containers(std::vector<int> &source);
        //* the constructor with input parameters: it takes the size of the array, norm and random generator limits as parameters.
        //*type of the array is double in this case
        Containers(std::vector<double> &source, size_t size, double norm, double left, double right);
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
