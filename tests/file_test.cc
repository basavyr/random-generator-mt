#include "../include/filestream.hh"

//use smart pointer for class instantation
#include <memory>

inline void line() { std::cout << '\n'; }

int main()
{
    const std::string file_name = "test_file";
    const std::string file_ext = ".dat";
    const int n_files = 10;
    //creates the files in which containers are stored.
    auto file = std::make_unique<file::Filestream>(file_name, n_files, file_ext);
}