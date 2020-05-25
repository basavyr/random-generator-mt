#include "../include/filestream.hh"

inline void line() { std::cout << '\n'; }

int main()
{
    const std::string file_name = "rng_data";
    const std::string file_ext = ".rng";
    const int n_files = 300;
    //creates the files in which containers are stored.
    auto file = std::make_unique<file::Filestream>(file_name, n_files, file_ext);
}